#include <iostream>
#include <string>
#include <algorithm>

class big_integer {
private:
    std::string value;

public:
    big_integer() = default;

    big_integer(const std::string& num) : value(num) {}

    big_integer(std::string&& num) : value(std::move(num)) {}

    big_integer& operator=(const big_integer& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    big_integer& operator=(big_integer&& other) noexcept {
        if (this != &other) {
            value = std::move(other.value);
        }
        return *this;
    }

    big_integer operator+(const big_integer& other) const {
        std::string result;
        int carry = 0;
        int i = value.size() - 1;
        int j = other.value.size() - 1;

        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0) {
                sum += value[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += other.value[j] - '0';
                j--;
            }
            carry = sum / 10;
            sum %= 10;
            result.push_back(sum + '0');
        }

        std::reverse(result.begin(), result.end());
        return big_integer(std::move(result));
    }

    big_integer operator*(int multiplier) const {
        std::string result;
        int carry = 0;

        for (int i = value.size() - 1; i >= 0; i--) {
            int product = (value[i] - '0') * multiplier + carry;
            carry = product / 10;
            product %= 10;
            result.push_back(product + '0');
        }

        while (carry != 0) {
            result.push_back(carry % 10 + '0');
            carry /= 10;
        }

        std::reverse(result.begin(), result.end());
        return big_integer(std::move(result));
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        os << num.value;
        return os;
    }
};

int main() {
    big_integer number1("114575");
    big_integer number2("78524");
    big_integer result = number1 + number2;
    std::cout << result; // 193099

    return 0;
}
