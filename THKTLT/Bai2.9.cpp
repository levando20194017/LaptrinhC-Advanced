#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
using namespace std;
const int LIMIT = 100;
const int number_ITER = 100000;
const int number_INPUTS = number_ITER * 100;
double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}
double x[number_INPUTS];
void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < number_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

const int N = 1000000;
double y[N + 1];

void precalc() {
    double delta = 2.0 * LIMIT / N;
    for (int i = 0; i <= N; i++)
        y[i] = sigmoid_slow(-LIMIT + i * delta);
}

double sigmoid_fast(double x) {
    if (x < -LIMIT) return 0;
    if (x > LIMIT) return 1;
    double delta = 2.0 * LIMIT / N;
    int i = (x + LIMIT) / delta;
    return (y[i+1] - y[i]) / delta * (x - (-LIMIT + i *delta)) + y[i];
}

double benchmark(double (*calc)(double), vector<double> &result) {
    const int number_TEST = 1000;
    double taken = 0;
    result = vector<double>();
    result.reserve(number_ITER);
    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < number_TEST; ++t) {
            double sum = 0;
        for (int i = 0; i < number_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == number_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}
bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}
int main() {
	printf("Le Van Do 20194017\n");
    prepare_input();
    precalc();
    vector<double> a, b;
    printf("Slow version\n");
    double slow = benchmark(sigmoid_slow, a);
    printf("Fast version\n");
    double fast = benchmark(sigmoid_fast, b);
    if (is_correct(a, b)) {
        printf("Correct answer! Your code is %.2f%% faster\n", slow / fast * 100.0);
    } else {
        printf("Wrong answer!\n");
    }
    return 0;
}
