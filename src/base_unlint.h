#include <vector>
#include <string>

namespace unlint {

// non-negative integer
class base_unlint {
protected:
	static const long long BASE = 1000000000000000000LL, // major system base
		BASE_S = 1000000000; // auxiliary system base
	static const char LEN = 18; // length of digits

	std::vector<long long> v_;

	void rm_leading_zeros(); // removes leading zeros

public:
	base_unlint(int = 0);
	base_unlint(unsigned);
	base_unlint(long);
	base_unlint(unsigned long);
	base_unlint(long long);
	base_unlint(unsigned long long);
	base_unlint(const char*);
	base_unlint(const std::string&);
	base_unlint(const base_unlint&);

	~base_unlint() {}

	template<class C>
	base_unlint& operator=(const C& other) {
		base_unlint(other).swap(*this);
		return *this;
	}

	std::size_t size() const; // returns number of digits
	std::string str() const;
	void swap(base_unlint& other) { v_.swap(other.v_); }

	base_unlint& operator++();
	base_unlint operator++(int);
	base_unlint& operator--();
	base_unlint operator--(int);
	base_unlint& operator+=(const base_unlint& other);
	base_unlint& operator-=(const base_unlint& other);
	base_unlint& operator*=(const base_unlint& other);
	base_unlint& operator/=(const base_unlint& other);
	base_unlint& operator%=(const base_unlint& other);
	base_unlint& gcd(const base_unlint& other);
	base_unlint& pow(const base_unlint& other);
	base_unlint& factorial();
	int compare(const base_unlint& other) const;
};

inline base_unlint operator+(const base_unlint& other) {
	return base_unlint(other);
}

inline base_unlint operator+(const base_unlint& a, const base_unlint& b) {
	return base_unlint(a) += b;
}
inline base_unlint operator-(const base_unlint& a, const base_unlint& b) {
	return base_unlint(a) -= b;
}
inline base_unlint operator*(const base_unlint& a, const base_unlint& b) {
	return base_unlint(a) *= b;
}
inline base_unlint operator/(const base_unlint& a, const base_unlint& b) {
	return base_unlint(a) /= b;
}
inline base_unlint operator%(const base_unlint& a, const base_unlint& b) {
	return base_unlint(a) %= b;
}
inline bool operator==(const base_unlint& a, const base_unlint& b) {
	return a.compare(b) == 0;
}
inline bool operator!=(const base_unlint& a, const base_unlint& b) {
	return a.compare(b) != 0;
}
inline bool operator<(const base_unlint& a, const base_unlint& b) {
	return a.compare(b) < 0;
}
inline bool operator>(const base_unlint& a, const base_unlint& b) {
	return a.compare(b) > 0;
}
inline bool operator<=(const base_unlint& a, const base_unlint& b) {
	return a.compare(b) <= 0;
}
inline bool operator>=(const base_unlint& a, const base_unlint& b) {
	return a.compare(b) >= 0;
}

} // namespace unlint
