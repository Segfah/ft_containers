#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;


		reverse_iterator() : _ptr() {};
		explicit reverse_iterator (iterator_type it) : _ptr(it) {};
		
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) : _ptr(rev_it.base()) {};

		template <class Iter>
		reverse_iterator & operator=(reverse_iterator<Iter> const &src)
		{
			this->_ptr = src.base();
			return (*this);
		};

		~reverse_iterator() {}

		iterator_type base() const { return (this->_ptr); };
		reference operator*() const
		{
			Iterator tmp = this->_ptr;
			return (*--tmp);
		};
		reverse_iterator&	operator++() { this->_ptr--; return (*this); };
		reverse_iterator	operator++(int) { return (reverse_iterator(this->_ptr--)); };

		reverse_iterator&	operator+=(difference_type n) { this->_ptr -= n; return(*this);}

		reverse_iterator&	operator--() { this->_ptr++; return (*this); };
		reverse_iterator	operator--(int) { return (reverse_iterator(this->_ptr++)); };

		reverse_iterator&	operator-=(difference_type n) { this->_ptr += n; return(*this);}

		pointer				operator->() const { return (&(this->operator*())); }
		reference			operator[] (difference_type n) const { return (this->base()[-n -1]); }

		reverse_iterator operator+ (difference_type n) const{
			return (reverse_iterator(base().operator-(n)));
		};
		reverse_iterator operator- (difference_type n) const{
			return (reverse_iterator(base().operator+(n)));
		};
		difference_type		operator-(const reverse_iterator<Iterator> &u) { return u.base().operator-(_ptr); };

		protected:
		Iterator	_ptr;
	};

	//Non-member function overloads

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs.base() == rhs.base()); }

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs.base() != rhs.base()); }

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() < rhs.base());}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() <= rhs.base());}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() > rhs.base());}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {return (lhs.base() >= rhs.base());}

	template <class Iter1, class Iter2>
	bool operator==(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs){return (lhs.base() == rhs.base());}

	template <class Iter1, class Iter2>
	bool operator!=(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs) {return (lhs.base() != rhs.base()); }

	template <class Iter1, class Iter2>
	bool operator>(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs) { return (lhs.base() < rhs.base()); }

	template <class Iter1, class Iter2>
	bool operator>=(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs) { return (lhs.base() <= rhs.base()); }

	template <class Iter1, class Iter2>
    bool operator<(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs) { return (lhs.base() > rhs.base()); }

	template <class Iter1, class Iter2>
	bool operator<=(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs) { return (lhs.base() >= rhs.base()); }

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type  n, const reverse_iterator<Iterator>& x){ return (reverse_iterator<Iterator>(x.base() - n)); }


};

#endif