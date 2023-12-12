///Щоб запустити програму потрібно прибрати коментарі програми /**/, або ж скопіювати її і вставити в кінець і
///запустити



///task2

///1, На вхід дається бінарний масив nums, поверніть максимальну кількість повторень 1-ці в масиві 

/*
#include <iostream> 

#include <vector> 



// Функція для знаходження максимальної кількості повторень 1-ці в бінарному масиві 

int findMaxConsecutiveOnes(const std::vector<int>& nums) {

    int maxCount = 0;

    int currentCount = 0;



    for (int num : nums) {

        if (num == 1) {

            // Якщо зустріли 1, збільшуємо поточну кількість 

            currentCount++;

        }
        else {

            // Якщо зустріли 0, збільшуємо максимальну кількість, якщо поточна більша 

            maxCount = std::max(maxCount, currentCount);

            currentCount = 0; // Обнуляємо поточну кількість 

        }

    }



    // Перевірка для останньої послідовності 1-ць, якщо вона закінчилася 

    maxCount = std::max(maxCount, currentCount);



    return maxCount;

}



int main() {

    // Приклад 1 

    std::vector<int> nums1 = { 1, 1, 0, 1, 1, 1 };

    std::cout << "Input: [1,1,0,1,1,1]\nOutput: " << findMaxConsecutiveOnes(nums1) << "\n\n";



    // Приклад 2 

    std::vector<int> nums2 = { 1, 0, 1, 1, 0, 1 };

    std::cout << "Input: [1,0,1,1,0,1]\nOutput: " << findMaxConsecutiveOnes(nums2) << "\n\n";



    return 0;

}
*/




///2, Дано масив nums цілих чисел, поверніть, скільки з них містять парну кількість цифр. 
 
/*
#include <iostream>

#include <vector>



// Функція для знаходження кількості чисел з парною кількістю цифр

int countNumbersWithEvenDigits(const std::vector<int>& nums) {

    int count = 0;



    for (int num : nums) {

        // Перевірка, чи кількість цифр парна

        int digitCount = 0;

        while (num != 0) {

            digitCount++;

            num /= 10;

        }



        if (digitCount % 2 == 0) {

            count++;

        }

    }



    return count;

}



int main() {

    // Приклад 1

    std::vector<int> nums1 = {12, 345, 2, 6, 7896};

    std::cout << "Input: [12, 345, 2, 6, 7896]\nOutput: " << countNumbersWithEvenDigits(nums1) << "\n\n";



    // Приклад 2

    std::vector<int> nums2 = {555, 901, 482, 1771};

    std::cout << "Input: [555, 901, 482, 1771]\nOutput: " << countNumbersWithEvenDigits(nums2) << "\n\n";



    return 0;

}


*/


///3, Дано масив цілих чисел nums, відсортований за неспаданням, повертає масив квадратів кожного числа, відсортованого за неспаданням.



/*

#include <iostream>
#include <vector>

// Функція для знаходження квадратів чисел та їх сортування
std::vector<int> sortedSquares(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, 0);

    int left = 0;
    int right = n - 1;
    int index = n - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }

        index--;
    }

    return result;
}

int main() {
    // Приклад 1
    std::vector<int> nums1 = {-4, -1, 0, 3, 10};
    std::vector<int> result1 = sortedSquares(nums1);

    std::cout << "Input: [-4, -1, 0, 3, 10]\nOutput: [";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << "]\n\n";

    // Приклад 2
    std::vector<int> nums2 = {-7, -3, 2, 3, 11};
    std::vector<int> result2 = sortedSquares(nums2);

    std::cout << "Input: [-7, -3, 2, 3, 11]\nOutput: [";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << "]\n\n";

    return 0;
}

*/


///4, Дано масив цілих чисел фіксованої довжини arr, дублюйте кожне входження нуля, зрушуючи інші елементи вправо.



/*

#include <iostream>
#include <vector>

// Функція для дублювання кожного входження нуля та зрушення інших елементів вправо
void duplicateZeros(std::vector<int>& arr) {
    int n = arr.size();
    int zeroCount = 0;

    // Лічильник кількості нулів в масиві
    for (int num : arr) {
        if (num == 0) {
            zeroCount++;
        }
    }

    // Починаємо з кінця масиву
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            // Якщо елемент - нуль, дублюємо його і збільшуємо лічильник
            if (i + zeroCount < n) {
                arr[i + zeroCount] = 0;
            }
            zeroCount--;
            // Дублюємо нуль другий раз, якщо лічильник ще не зменшився
            if (i + zeroCount < n) {
                arr[i + zeroCount] = 0;
            }
        } else {
            // Якщо елемент не є нулем, просто зрушуємо його
            if (i + zeroCount < n) {
                arr[i + zeroCount] = arr[i];
            }
        }
    }
}

int main() {
    // Приклад 1
    std::vector<int> arr1 = {1, 0, 2, 3, 0, 4, 5, 0};
    std::cout << "Input: [1, 0, 2, 3, 0, 4, 5, 0]\nOutput: [";
    duplicateZeros(arr1);
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << "]\n\n";

    // Приклад 2
    std::vector<int> arr2 = {1, 2, 3};
    std::cout << "Input: [1, 2, 3]\nOutput: [";
    duplicateZeros(arr2);
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << "]\n\n";

    return 0;
}

*/






///5, Вам надано два масиви цілих чисел nums1 і nums2, відсортовані в порядку неубування, і
///два цілих числа m і n, що представляють кількість елементів у nums1 і nums2 відповідно.


/*

#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    // Починаємо з кінця об'єднаного масиву
    int index = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    // Об'єднання масивів nums1 і nums2
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[index--] = nums1[i--];
        } else {
            nums1[index--] = nums2[j--];
        }
    }

    // Додаємо залишок з nums2, якщо він є
    while (j >= 0) {
        nums1[index--] = nums2[j--];
    }
}

int main() {
    // Приклад 1
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    std::cout << "Input: [1, 2, 3, 0, 0, 0], [2, 5, 6]\nOutput: [";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << "]\n\n";

    // Приклад 2
    std::vector<int> nums3 = {1};
    int m2 = 1;
    std::vector<int> nums4 = {};
    int n2 = 0;

    merge(nums3, m2, nums4, n2);

    std::cout << "Input: [1], []\nOutput: [";
    for (int num : nums3) {
        std::cout << num << " ";
    }
    std::cout << "]\n\n";

    // Приклад 3
    std::vector<int> nums5 = {0};
    int m3 = 0;
    std::vector<int> nums6 = {1};
    int n3 = 1;

    merge(nums5, m3, nums6, n3);

    std::cout << "Input: [0], [1]\nOutput: [";
    for (int num : nums5) {
        std::cout << num << " ";
    }
    std::cout << "]\n\n";

    return 0;
}

*/





/*6, Маючи цілочисельний масив nums, відсортований у порядку не спадання, видаліть дублікати на місці, 
щоб кожен унікальний елемент з’являвся лише один раз. Відносний порядок елементів має бути незмінним. 
Потім повертає кількість унікальних елементів у nums.

Вважайте, що кількість унікальних елементів nums дорівнює k, щоб бути прийнятим, вам потрібно зробити наступне:
- Змініть масив nums так, щоб перші k елементів nums містили унікальні елементи в тому порядку, в якому вони були присутні в nums спочатку. Решта елементів nums не важливі, як і розмір nums.
- Поверніть k.
*/



/*

#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int n = nums.size();

    // Обробляємо випадок пустого масиву
    if (n == 0) {
        return 0;
    }

    int uniqueCount = 1;  // Лічильник унікальних елементів

    // Проходимо через масив nums і знаходимо кількість унікальних елементів
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueCount] = nums[i];
            uniqueCount++;
        }
    }

    return uniqueCount;
}

int main() {
    // Приклад 1
    std::vector<int> nums1 = {1, 1, 2};
    int k1 = removeDuplicates(nums1);
    std::cout << "Input: [1, 1, 2]\nOutput: " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        std::cout << nums1[i] << " ";
    }
    std::cout << "_]\n\n";

    // Приклад 2
    std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = removeDuplicates(nums2);
    std::cout << "Input: [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]\nOutput: " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) {
        std::cout << nums2[i] << " ";
    }
    std::cout << "_]\n\n";

    return 0;
}


*/


/*7, Потрібно написати функцію
Дано масив arr цілих чисел, перевірте, чи існують два індекси i та j такі, що:
i != j
0 <= i, j < arr.length
arr[ i ] == 2 * arr[ j ]
*/




/*
#include <iostream>
#include <vector>

bool checkIfDoubleExists(std::vector<int>& arr) {
    int n = arr.size();

    // Перебираємо всі можливі пари індексів (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Перевіряємо умову arr[i] == 2 * arr[j] та i != j
            if (i != j && arr[i] == 2 * arr[j]) {
                return true;  // Знайдено потрібну пару
            }
        }
    }

    return false;  // Не знайдено потрібну пару
}

int main() {
    // Приклад 1
    std::vector<int> arr1 = {10, 2, 5, 3};
    bool result1 = checkIfDoubleExists(arr1);
    std::cout << "Input: [10, 2, 5, 3]\nOutput: " << std::boolalpha << result1 << "\n\n";

    // Приклад 2
    std::vector<int> arr2 = {3, 1, 7, 11};
    bool result2 = checkIfDoubleExists(arr2);
    std::cout << "Input: [3, 1, 7, 11]\nOutput: " << std::boolalpha << result2 << "\n\n";

    return 0;
}

*/






///8, Дано масив цілих чисел arr, повертає true тоді і тільки якщо це дійсний гірський масив.



/*

#include <iostream>
#include <vector>

bool validMountainArray(std::vector<int>& arr) {
    int n = arr.size();
    if (n < 3) {
        return false;
    }

    int peak = 0;

    // Знаходимо пік гірського масиву
    while (peak < n - 1 && arr[peak] < arr[peak + 1]) {
        peak++;
    }

    // Перевіряємо, чи існує пік та чи немає спадань до кінця
    if (peak == 0 || peak == n - 1) {
        return false;
    }

    while (peak < n - 1 && arr[peak] > arr[peak + 1]) {
        peak++;
    }

    return peak == n - 1;
}

int main() {
    // Приклад 1
    std::vector<int> arr1 = {2, 1};
    bool result1 = validMountainArray(arr1);
    std::cout << "Input: [2, 1]\nOutput: " << std::boolalpha << result1 << "\n\n";

    // Приклад 2
    std::vector<int> arr2 = {3, 5, 5};
    bool result2 = validMountainArray(arr2);
    std::cout << "Input: [3, 5, 5]\nOutput: " << std::boolalpha << result2 << "\n\n";

    // Приклад 3
    std::vector<int> arr3 = {0, 3, 2, 1};
    bool result3 = validMountainArray(arr3);
    std::cout << "Input: [0, 3, 2, 1]\nOutput: " << std::boolalpha << result3 << "\n\n";

    return 0;
}


*/









