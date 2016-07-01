// UnionFind.cpp : ���C�� �v���W�F�N�g �t�@�C���ł��B

#include "stdafx.h"

#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_set>
#include <unordered_map>
#endif


//quack
// #include <bits/stdc++.h>
using namespace std;


template<typename T>
class UF
{
public:
	UF() {
		size = 0;
	}

	//�l��}������
	void push( T a ) {
		M[a] = size;
		V.push_back( size );
		rank.push_back( 0 );
		C.push_back( 1 );
		size++;
	}

	//�����O���[�v�ɂ���
	void unite( T a, T b ) {
		long long int x = find( M[a] );
		long long int y = find( M[b] );
		if( x == y )return;
		if( rank[x] < rank[y] ) {
			V[x] = y;
			C[y] += C[x];
		} else {
			V[y] = x;
			C[x] += C[y];
			if( rank[x] == rank[y] )rank[x]++;
		}
	}

	void merge( T a, T b ) {
		unite( a, b );
	}

	//�����O���[�v�ɂ��邩�ǂ������肷��
	bool same( T a, T b ) {
		return find( M[a] ) == find( M[b] );
	}

	//�����O���[�v���邩����Ԃ�
	long long int group() {
		set<long long int>S;
		for( long long int i = 0; i < V.size(); i++ ) {
			S.insert( find( V[i] ) );
		}
		return S.size();
	}

	//�O���[�v�ɑ����Ă��鐔��Ԃ�
	long long int count( T a ) {
		return C[find( M[a] )];
	}

private:
	vector<long long int>C, V, rank;
	map < T, long long int>M;
	long long int size;

	//�c��܂ł��ǂ�
	long long int find( long long int x ) {
		if( V[x] == x )return x;
		else return V[x] = find( V[x] );
	}
};

int main() {
	UF<long long int> uf;
	for( size_t i = 0; i < 10; i++ ) {
		uf.push( i );
	}
	assert( uf.group() == 10 );
	uf.merge( 0, 1 );
	assert( uf.group() == 9 );
	assert( uf.count( 0 ) == 2 );
	assert( uf.count( 9 ) == 1 );
	

}