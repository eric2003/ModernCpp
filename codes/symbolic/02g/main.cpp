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
    requires Trait < std :: remove_cvref_t < Arg > >:: value
    constexpr symbol_binder < symbol , Arg && > operator =( Arg && arg ) const {
        return symbol_binder (*this, std::forward < Arg >( arg ));
    }
};

// Metafunction hierarchy
template < class T >
struct metafunction_wrapper_0 {};
template < template < class ... > class F >
struct metafunction_wrapper_1 {};
template < template < template < class ... > class ... > class F >
struct metafunction_wrapper_2 {};
template < template < template < template < class ... > class ... > class ... > class F >
struct metafunction_wrapper_3 {};
template < template < template < template < template < class ... > class ...... > class ... > class ... > class F >
struct metafunction_wrapper_4 {};

// Use cases
metafunction_wrapper_1 < metafunction_wrapper_0 > x1 ; // OK
metafunction_wrapper_2 < metafunction_wrapper_1 > x2 ; // OK
metafunction_wrapper_3 < metafunction_wrapper_2 > x3 ; // OK
metafunction_wrapper_4 < metafunction_wrapper_3 > x4 ; // OK

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
