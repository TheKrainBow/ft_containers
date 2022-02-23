#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector;
};


template<typename T, typename Alloc>
class ft::vector
{

	private:
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
	
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;
	
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		
		vector() {};
		~vector() {};

		vector &		operator=( vector const & rhs );


};
#endif /* ********************************************************** VECTOR_H */