#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>

class Student {
private:
    //pair for name
    std::pair<int, int> name;
    //status
    bool vaccinated;

public:
    Student(std::pair<int, int> n, bool v)
        : name(n), vaccinated(v) {}

    auto get_name() const {
        return name;
    }

    bool is_vaccinated() const {
        return vaccinated;
    }

    //Overload the required operators for the Student class so that a vector of students can be sorted using the STL std::sort() function

    bool operator==(const Student& p) const {
        return name == p.name;
    }

    bool operator<(const Student& p) const {
        return name < p.name;
    }

    bool operator>(const Student& p) const {
        return name > p.name;
    }
};

//Creates a random student 
Student generate_random_Student(int max) {
    static std::random_device rd;
    static std::mt19937 rand(rd());

    std::uniform_int_distribution<int> uniform_dist(1, max);

    auto random_name = std::make_pair(
        uniform_dist(rand),
        uniform_dist(rand)
    );

    bool is_vaccinated = uniform_dist(rand) % 2 == 1;

    return Student(random_name, is_vaccinated);
}

//binary search
bool needs_vaccination(const Student& P,const std::vector<Student>& people) {
    auto first = people.begin();
    auto last = people.end();

    while (first < last) {
        auto range_length = std::distance(first, last);
        auto mid_index = range_length / 2;
        auto mid = first + mid_index;

        if (*mid == P) {
            return !mid->is_vaccinated();
        }
        else if (*mid > P) {
            last = mid;
        }
        else {
            first = mid + 1;
        }
    }

    return true;
}

//Testing func
void search_test(int size, const Student& p) {
    std::vector<Student> people;

    for (int i = 0; i < size; i++) {
        people.push_back(generate_random_Student(size));
    }

    std::sort(people.begin(), people.end());

    auto begin = std::chrono::steady_clock::now();

    bool result = needs_vaccination(p, people);

    auto end = std::chrono::steady_clock::now();

    std::cout << "Time taken to search = "
              << std::chrono::duration_cast<
                     std::chrono::microseconds
                 >(end - begin).count()
              << " microseconds\n";

    if (result) {
        std::cout << "Student ("
                  << p.get_name().first << " "
                  << p.get_name().second
                  << ") needs vaccination.\n";
    }
    else {
        std::cout << "Student ("
                  << p.get_name().first << " "
                  << p.get_name().second
                  << ") does not need vaccination.\n";
    }
}

int main() {
    std::cout << "===== Procedure, flu shot binary search =====\n";

    auto p = generate_random_Student(1000);

    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);

    return 0;
}