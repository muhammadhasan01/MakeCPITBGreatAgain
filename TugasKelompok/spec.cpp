#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int NMax = 2e5;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, M;
    vector<int> U;
    vector<int> V;
    int res;

    void InputFormat() {
        LINE(N, M);
        LINES(U, V) % SIZE(M);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMax);
        CONS(1 <= M && M <= NMax);
        CONS(eachElementBetween(U, 1, N));
        CONS(eachElementBetween(V, 1, N));
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"5 5",
        	"1 2",
        	"2 3",
        	"3 4",
        	"3 5",
        	"1 5"
        });
        Output({
        	"1"
        });
    }

    void SampleTestCase2() {
    	Input({
    		"6 3",
    		"1 2",
    		"2 6",
    		"3 4"
    	});
    	Output({
    		"3"
    	});
    }

    void BeforeTestCase() {
        U.clear();
        V.clear();
    }

    void TestCases() {
    	for (int i = 0; i < 5; i++) {
    		CASE(N = rnd.nextInt(10, NMax), M = rnd.nextInt(1, N - 2), randomUnconnected(N, M, U, V));
    	}
    	for (int i = 0; i < 5; i++) {
    		CASE(N = rnd.nextInt(NMax / 2, NMax), M = rnd.nextInt(N - 1, NMax), randomGraph(N, M, U, V));
    	}
    }
 
private:

	void renumber(int n, vector<int>& u, vector<int>& v) {
	    vector<int> permutation;
	    for (int i = 0; i < n; i++) {
	        permutation.push_back(i + 1);
	    }
	    rnd.shuffle(permutation.begin(), permutation.end());
	    for (int i = 0; i < u.size(); i++) {
	        u[i] = permutation[u[i] - 1];
	        v[i] = permutation[v[i] - 1];
	    }
	}

	void randomUnconnected(int n, int m, vector<int>& u, vector<int>& v) {
	    for (int i = 1; i <= m; i++) {
	        u.push_back(i + 1);
	        v.push_back(rnd.nextInt(1, i));
	    }
	    renumber(n, u, v);
	}

	void randomTree(int n, vector<int>& u, vector<int>& v) {
	    for (int i = 1; i < n; i++) {
	        u.push_back(i + 1);
	        v.push_back(rnd.nextInt(1, i));
	    }
	    renumber(n, u, v);
	}

	void randomGraph(int n, int m, vector<int>& u, vector<int>& v) {
	    randomTree(n, u, v);
	    while (u.size() < m) {
	        int newU = rnd.nextInt(1, N - 1);
	        int newV = rnd.nextInt(newU + 1, N);
	        u.push_back(newU);
	        v.push_back(newV);
	    }
	}
	
};