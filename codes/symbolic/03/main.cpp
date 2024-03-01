#include <type_traits>
#include <iostream>
#include <memory>

//Remove lvalue references
template <class T >
struct remove_lvalue_reference : std::type_identity <T> {};

template <class T >
requires std :: is_lvalue_reference_v<T>
struct remove_lvalue_reference <T>: std::type_identity < std::remove_reference_t<T> > {};

template <class T >
using remove_lvalue_reference_t = remove_lvalue_reference<T>::type;

//Remove rvalue references
template <class T >
struct remove_rvalue_reference : std::type_identity <T>{};

template <class T >
requires std::is_rvalue_reference_v<T>
struct remove_rvalue_reference <T>: std::type_identity < std::remove_reference_t<T> >{};

template <class T >
using remove_rvalue_reference_t = remove_rvalue_reference <T>::type;

template <class T >
struct requalify_as_const : std::conditional <
    std::is_lvalue_reference_v <T > ,
    std::add_lvalue_reference_t < std::add_const_t < std::remove_reference_t <T >>> ,
    std::conditional_t <
       std::is_rvalue_reference_v <T > ,
       std::add_rvalue_reference_t < std::add_const_t < std::remove_reference_t <T >>>,
       std::add_const_t <T >
    >
> {};

template <class T >
using requalify_as_const_t = requalify_as_const <T >::type;

template <class T >
struct requalify_as_volatile ;
template <class T >
using requalify_as_volatile_t = requalify_as_volatile <T >::type;

template <class T >
struct requalify_as_cv ;
template <class T >
using requalify_as_cv_t = requalify_as_cv <T >::type ;

template < typename >
struct symbol_id {
	static constexpr auto singleton = []{};
	static constexpr const void * address = std::addressof( singleton );
};

//Final lightweight binder leveraging the previously-defined traits
// Symbol binder class definition
template <class Symbol , class T >
struct symbol_binder {
    // Types and constants
    using symbol_type = Symbol ;
    using value_type = std::remove_cvref_t<T>;
    static constexpr Symbol symbol = {};
    // Constructors
    template <class U >
    requires std::is_convertible_v < U && , requalify_as_const_t < remove_rvalue_reference_t <T >>>
    constexpr symbol_binder ( Symbol , U && x) noexcept (
        std::is_nothrow_convertible_v <U && , requalify_as_const_t < remove_rvalue_reference_t <T > >>
    ): value ( std::forward <U >( x )) {}
    // Accessors
    const value_type & operator ()() const noexcept { return value ;}
    // Implementation details : data members
    private :
    requalify_as_const_t < remove_rvalue_reference_t <T > > value ;
};


template <class Lhs , class Rhs >
constexpr std::strong_ordering operator <=>(
    symbol_id< Lhs >,
    symbol_id< Rhs >
) {
      return std::compare_three_way {} (
           symbol_id< Lhs >::address,
           symbol_id< Rhs >::address
      );
}

template <class T >
struct unconstrained : std::true_type {};

template <class T >
struct real : std::is_floating_point <T > {};

// Deduction guide
template <class Symbol , class T >
symbol_binder ( Symbol , T &&) -> symbol_binder < Symbol , T && >;

// Symbol
template <template <class ... > class Trait = unconstrained, auto Id = symbol_id< decltype([]{})>{}  >
struct symbol {
	static constexpr auto id = Id;
    template <class Arg >
    requires Trait < std::remove_cvref_t < Arg > >::value
    constexpr symbol_binder < symbol , Arg && > operator =( Arg && arg ) const {
        return symbol_binder (*this, std::forward < Arg >( arg ));
    }
};

// Type trait
template <class >
struct is_symbolic : std::false_type {};

// Variable template
template <class T >
inline constexpr bool is_symbolic_v = is_symbolic <T >::value;

// Concept
template <class T >
concept symbolic = is_symbolic_v<T>;

// Index constant type
template < std::size_t I >
struct index_constant : std::integral_constant < std::size_t, I > {};

// Index constant variable template
template < std::size_t I >
inline constexpr index_constant <I> index = {};

// An indexed substitution element
template < std::size_t I, typename Binder >
struct substitution_element ;

// A helper class to build the substitution
template <class Sequence, class ... T >
struct substitution_base;

// The substitution wrapper itself
template <class ... Binders >
struct substitution;

// Substitution providing an index sequence to its base
template <class ... Binders >
struct substitution : substitution_base < std::index_sequence_for < Binders ... >, Binders ... > {
    using base = substitution_base < std::index_sequence_for < Binders ... > , Binders ... >;
    using base::base;
    using base::operator [];
};

// Deduction guide
template <class ... Binders >
substitution ( const Binders &...) -> substitution < Binders ... >;

//template < std::size_t I, typename Binder B >
template < std::size_t I, typename Binder >
struct substitution_element {
    // Types and constants
    using index = index_constant<I>;
    using id_type = decltype( Binder::symbol_type::id );
    // Constuctor
    constexpr substitution_element ( const Binder & b ): _binder (b) {}
    // Access by index
    constexpr const Binder& operator []( index ) const {
        return _binder ;
    }
    // Access by id: all the magic happen here
    constexpr const Binder& operator []( id_type ) const {
        return _binder ;
    }
    // Implementation details : data members
    //private : const B _binder ;
	private : const Binder _binder ;
};

// Substitution base deriving from each binder
template < std :: size_t ... Index , class ... Binders >
struct substitution_base < std::index_sequence < Index ... > , Binders ... >
 : substitution_element < Index , Binders >... {
    using index_sequence = std::index_sequence < Index ... >;
    using substitution_element < Index , Binders >:: operator []...;
    constexpr substitution_base ( const Binders &... x ): substitution_element < Index , Binders >( x )... {}
};

template < typename Expression >
struct formula {
    // Types and constants
    using expression = Expression;
    // Constructor
    constexpr formula ( Expression expr ) noexcept {};
    // Call operator where substitution happens
    template <class ... Args >
    constexpr auto operator ()( Args ... args ) const noexcept {
        return expression {}( substitution ( args ...));
    }
};

int main(int argc, char* argv[])
{
	symbol x;
	symbol y;
	symbol z;
	
	std::cout << "x.id < x.id := " << ( x.id < x.id ) << std::endl; 
	std::cout << "x.id < y.id := " << ( x.id < y.id ) << std::endl; 
	std::cout << "y.id < x.id := " << ( y.id < x.id ) << std::endl; 
	std::cout << "x.id < z.id := " << ( x.id < z.id ) << std::endl; 
	std::cout << "z.id < x.id := " << ( z.id < x.id ) << std::endl; 
	std::cout << "y.id < z.id := " << ( y.id < z.id ) << std::endl; 
	std::cout << "z.id < y.id := " << ( z.id < y.id ) << std::endl; 
	
	//std::cout << std::is_same_v< decltype(x), decltype(x) > << std::endl; 
	//std::cout << std::is_same_v< decltype(x), decltype(y) > << std::endl; 
	
	return 0;
}
