#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <cstring>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector;
};


template<typename T, typename Alloc>
class ft::vector
{
// ---------------------------------------------------------------------------------------------------------------------------- //
// ---------                                           TYPEDEF AND METHODS                                           ---------- //
// ---------------------------------------------------------------------------------------------------------------------------- //
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
	
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;
	
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		// Constructors
		explicit vector(const allocator_type &alloc = allocator_type()) : _array(NULL), _size(0), _capacity(0), _allocator(alloc) {};
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			_allocator = alloc;
			_capacity = 0;
			_size = 0;
			reserve(n);
			for (size_type i = 0; i < n; i++)
				push_back(val);
		};
		template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
		vector(const vector &x);
		~vector()
		{
			_allocator.deallocate(_array, _capacity);
		};
		vector	&operator=( vector const &rhs );

		// Capacity Methods
		size_type size() const { return _size; };
		size_type capacity() const { return _capacity; };
		bool empty() const { return _size == 0; };
		size_type max_size() const { return _allocator.max_size() / sizeof(value_type); };
		void reserve (size_type n)
		{
			if (n <= _capacity)
				return ;
			upgradeCapacity(nextCapacity(n));
		};
		void resize(size_type n, value_type val = value_type())
		{
			if (n < 0)
				return ;
			while (_size > n)
				pop_back();
			while (_size < n)
				push_back(val);
				
		};

		// Element Access Methods
		reference operator[](size_type n) { return _array[n]; };
		const_reference operator[](size_type n) const { return _array[n]; };
		reference at(size_type n)
		{
			if (n > _size)
				throw std::out_of_range("Index out of bounds!");
			return _array[n];
		};
		const_reference at(size_type n) const
		{
			if (n > _size)
				throw std::out_of_range("Index out of bounds!");
			return _array[n];
		};
		reference front() { return _array[0]; };
		const_reference front() const { return _array[0]; };
		reference back() { return _array[_size - 1]; };
		const_reference back() const { return _array[_size - 1]; };

		// Modifier Methods
		template <class InputIterator>
  		void assign(InputIterator first, InputIterator last);
		void assign (size_type n, const value_type &val)
		{
			clear();
			reserve(n);
			for (size_type i = 0; i < n; i++)
				push_back(val);
		};
		void push_back (const value_type &val)
		{
			reserve(_size + 1);
			_array[_size] = val;
			_size++;
		};
		void pop_back()
		{
			_allocator.destroy(_array + _size - 1);
			_size--;
		};
		/*iterator insert (iterator position, const value_type &val)
		{
			insert(position, 1, val);
			return iterator(position--);
		};
		void insert (iterator position, size_type n, const value_type &val)
		{
			difference_type index = position - begin();
		
			reserve(_size + n);
			memmove(position + n, position, sizeof(size_type) * n);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(position + i, val);
			_size += n;
		};
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);
		iterator erase (iterator position)
		{
			return erase(position, position + 1);
		};
		iterator erase (iterator first, iterator last)
		{
			difference_type indexFirst = first - begin();
			difference_type indexLast = last - begin();
	
			for (difference_type i = indexFirst; i < indexLast; i++)
				_allocator.destroy(_array + i);
			memmove(_array + indexFirst, _array + indexLast, sizeof(value_type) * (_size - indexLast));
			_size -= (indexLast - indexFirst);
			return iterator(_array + indexFirst);
		};*/
		void swap (vector &x)
		{
			vector tmp = *this;

			*this = x;
			x = tmp;
		};
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_array + i);
			_size = 0;
		};
// ---------------------------------------------------------------------------------------------------------------------------- //
// ---------                                      MEMBER VARIABLE DECLARATION                                        ---------- //
// ---------------------------------------------------------------------------------------------------------------------------- //
	private:
		pointer			_array;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_allocator;

		size_type nextCapacity(size_type target = 0)
		{
			size_type tempCapacity = _capacity;

			if (!tempCapacity)
				tempCapacity++;
			while (tempCapacity < target)
				tempCapacity *= 2;
			return tempCapacity;
		}

		void upgradeCapacity(size_type _newCapacity = 0)
		{
			size_type newCapacity = _newCapacity ? _newCapacity : _capacity * 2;
			pointer _newArray = _allocator.allocate(newCapacity);
			for (int i = 0; i < _size ; i++)
				_newArray[i] = _array[i];
			if (_array)
				_allocator.deallocate(_array, _capacity);
			_capacity = newCapacity;
			_array = _newArray;
		}
};
#endif /* ********************************************************** VECTOR_H */