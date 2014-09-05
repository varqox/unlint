#include "base_unlint.h"
#include <cstring>

namespace unlint {

using std::vector;
using std::string;

void base_unlint::rm_leading_zeros(){
	vector<long long>::iterator it = v_.end();
	while (--it != v_.begin() && *it == 0) {}
	v_.erase(++it, v_.end());
}

base_unlint::base_unlint(int i): v_(1, i) {}

base_unlint::base_unlint(unsigned u): v_(1, u) {}

base_unlint::base_unlint(long l): v_(1, l) {
	if (l >= BASE) {
		v_.push_back(l / BASE);
		v_.front() -= v_.back() * BASE;
	}
}

base_unlint::base_unlint(unsigned long ul): v_(1, ul) {
	if (ul >= BASE) {
		v_.push_back(ul / BASE);
		v_.front() -= v_.back() * BASE;
	}
}

base_unlint::base_unlint(long long ll): v_(1, ll) {
	if (ll >= BASE) {
		v_.push_back(ll / BASE);
		v_.front() -= v_.back() * BASE;
	}
}

base_unlint::base_unlint(unsigned long long ull): v_(1, ull) {
	if (ull >= BASE) {
		v_.push_back(ull / BASE);
		v_.front() -= v_.back() * BASE;
	}
}

base_unlint::base_unlint(const char* _str) : v_() {
	size_t len = strlen(_str), next;
	if (len == 0)
		v_.assign(1, 0);
	else {
		v_.resize((len + LEN - 1) / LEN);
		next = len % LEN;
		if (next == 0)
			next = LEN;
		len = 0;
		for (vector<long long>::reverse_iterator i = v_.rbegin(); i != v_.rend(); ++i, next += LEN)
			for (;len < next; ++len) {
				*i *= 10;
				*i += _str[len] - '0';
			}
		rm_leading_zeros();
	}
}

base_unlint::base_unlint(const string& _str) : v_() {
	size_t len = _str.size(), next;
	if (len == 0)
		v_.assign(1, 0);
	else {
		v_.resize((len + LEN - 1) / LEN);
		next = len % LEN;
		if (next == 0)
			next = LEN;
		len = 0;
		for (vector<long long>::reverse_iterator i = v_.rbegin(); i != v_.rend(); ++i, next += LEN)
			for (;len < next; ++len) {
				*i *= 10;
				*i += _str[len] - '0';
			}
		rm_leading_zeros();
	}
}

base_unlint::base_unlint(const base_unlint& other): v_(other.v_) {}

size_t base_unlint::size() const {
	size_t res;
	long long last = v_.back();
	if (last < 1000000000LL) {
		if (last < 10000LL) {
			if (last < 100LL) {
				if (last < 10LL)
					res = 1;
				else
					res = 2;
			} else {
				if (last < 1000LL)
					res = 3;
				else
					res = 4;
			}
		} else {
			if (last < 1000000LL) {
				if (last < 100000LL)
					res = 5;
				else
					res = 6;
			} else {
				if (last < 100000000LL) {
					if (last < 10000000LL)
						res = 7;
					else
						res = 8;
				} else
					res = 9;
			}
		}
	} else {
		if (last < 10000000000000LL) {
			if (last < 100000000000LL) {
				if (last < 10000000000LL)
					res = 10;
				else
					res = 11;
			} else {
				if (last < 1000000000000LL)
					res = 12;
				else
					res = 13;
			}
		} else {
			if (last < 1000000000000000LL) {
				if (last < 100000000000000LL)
					res = 14;
				else
					res = 15;
			} else {
				if (last < 100000000000000000LL) {
					if (last < 10000000000000000LL)
						res = 16;
					else
						res = 17;
				} else
					res = 18;
			}
		}
	}
	return res + (v_.size() - 1) * LEN;
}

string base_unlint::str() const {
	string _str(size(), '0');
	long long k, l;
	vector<long long>::const_iterator it = v_.begin();
	for (string::iterator j, i = _str.end() - 1; it != v_.end(); i -= LEN, ++it) {
		j = i;
		k = *it;
		while (k) {
			l = k / 10;
			*(j--) += k - 10*l;
			k = l;
		}
	}
	return _str;
}

base_unlint& base_unlint::operator++() {
	vector<long long>::iterator i = v_.begin();
	while (i != v_.end()) {
		if (++*i < BASE)
			return *this;
		*i -= BASE;
		++i;
	}
	v_.push_back(1);
	return *this;
}

base_unlint base_unlint::operator++(int) {
	base_unlint res(*this);
	operator++();
	return res;
}

base_unlint& base_unlint::operator--() {
	vector<long long>::iterator i = v_.begin();
	while (i != v_.end() && --*i < 0) {
		*i += BASE;
		++i;
	}
	rm_leading_zeros();
	return *this;
}

base_unlint base_unlint::operator--(int) {
	base_unlint res(*this);
	operator--();
	return res;
}

base_unlint& base_unlint::operator+=(const base_unlint& other) {
	size_t len = other.v_.size(), i = 0;
	if (len > v_.size())
		v_.resize(len);
	bool add = false;
	for (; i < len; ++i) {
		v_[i] += other.v_[i];
		if (add)
			++v_[i];
		if (v_[i] >= BASE) {
			v_[i] -= BASE;
			add = true;
		} else
			add = false;
	}
	if (add) {
		for (len = v_.size(); i < len; ++i) {
			if (++v_[i] < BASE)
				return *this;
			v_[i] -= BASE;
		}
		if (i == len)
			v_.push_back(1);
	}
	return *this;
}

base_unlint& base_unlint::operator-=(const base_unlint& other) {
	size_t len = other.v_.size(), i = 0;
	bool sub = false;
	for (; i < len; ++i) {
		v_[i] -= other.v_[i];
		if (sub)
			--v_[i];
		if (v_[i] < 0) {
			v_[i] += BASE;
			sub = true;
		} else
			sub = false;
	}
	if (sub) {
		for (len = v_.size(); i < len && --v_[i] < 0; ++i)
			v_[i] += BASE;
	}
	rm_leading_zeros();
	return *this;
}

// base_unlint& base_unlint::operator*=(const base_unlint& other);

// base_unlint& base_unlint::operator/=(const base_unlint& other);

// base_unlint& base_unlint::operator%=(const base_unlint& other);

// base_unlint& base_unlint::gcd(const base_unlint& other);

// base_unlint& base_unlint::pow(const base_unlint& other);

// base_unlint& base_unlint::factorial();

int base_unlint::compare(const base_unlint& other) const {
	size_t i = v_.size();
	if (i < other.v_.size())
		return -1;
	if (i > other.v_.size())
		return 1;
	while (--i > 0 && v_[i] == other.v_[i]) {}
	if (v_[i] < other.v_[i])
		return -1;
	if (v_[i] > other.v_[i])
		return 1;
	return 0;
}

} // namespace unlint
