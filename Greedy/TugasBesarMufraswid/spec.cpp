#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAXN = 100;
const int MINA = -1e9;
const int MAXA = 1e9;

class ProblemSpec : public BaseProblemSpec {
protected:
    int r, c;
    long long res;
    vector<vector<int>> a;

    void InputFormat() {
        LINE(r, c);
        GRID(a) % SIZE(r, c);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= r && r <= 100);
        CONS(1 <= c && c <= 100);
        CONS(eachElementBetween(a, MINA, MAXA));
    }

private:
    bool eachElementBetween(const vector<vector<int>>& v, int lo, int hi) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0;j < v[i].size(); j++) {
                if (v[i][j] < lo || v[i][j] > hi) {
                    return false;
                }
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"3 2",
            "1 3",
            "-4 6",
            "2 -3",
        });
        Output({
        	"9"
        });
    }

    void SampleTestCase2() {
        Input({
        	"1 5",
			"-5 2 3 -2 4"
        });
        Output({
        	"7"
        });
    }

    void BeforeTestCase() {
        a.clear();
    }

    void TestCases() {
    	for (int i = 0; i < 5; i++) {
    		CASE(r = rnd.nextInt(1, 10), c = rnd.nextInt(1, 10), randomNumbers(MINA, MAXA, a));
    	}
    	CASE(r = rnd.nextInt(1, 10), c = rnd.nextInt(1, 10), randomNumbers(MINA, -1, a));
    	CASE(r = rnd.nextInt(1, 10), c = rnd.nextInt(1, 10), randomNumbers(MAXA / 2, MAXA, a));
        for (int i = 0; i < 5; i++) {
    		CASE(r = rnd.nextInt(20, 100), c = rnd.nextInt(20, 100), randomNumbers(MINA, MAXA, a));
    	}
    	CASE(r = rnd.nextInt(20, 100), c = rnd.nextInt(20, 100), randomNumbers(MINA, -1, a));
    	CASE(r = 100, c = 100, randomNumbers(MAXA / 2, MAXA, a));
    }
 
private:
	void randomNumbers(int minn, int maxn, vector<vector<int>>& a) {
		for (int i = 1; i <= r; i++) {
            vector<int> v;
		    for (int j = 1; j <= c; j++) {
                int num = rnd.nextInt(minn, maxn);
                v.push_back(num);
            }
            a.push_back(v);
		}
	}
};