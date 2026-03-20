#include <iostream>
#include <vector>


std::vector<int> GetKNearestElements(int k, int target, std::vector<int>& vec)
{
	auto it = std::lower_bound(vec.cbegin(), vec.cend(), target);

	int leftIdx = std::prev(it) - vec.cbegin();
	int rightIdx = std::next(it) - vec.cbegin();
	
	std::vector<int> nearestElements;
	nearestElements.emplace_back(*it);

	while (nearestElements.size() < k)
	{
		if (leftIdx <= -1 && rightIdx >= vec.size())
		{
			break;
		}

		if (leftIdx <= -1 && rightIdx < vec.size())
		{
			nearestElements.emplace_back(vec[rightIdx]);
			++rightIdx;
			continue;
		}

		if (leftIdx >= 0 && rightIdx >= vec.size())
		{
			nearestElements.emplace_back(vec[leftIdx]);
			--leftIdx;
			continue;
		}

		const int leftDistance = std::abs(vec[leftIdx] - target);
		const int rightDistance = std::abs(vec[rightIdx] - target);

		if (leftDistance <= rightDistance)
		{
			nearestElements.emplace_back(vec[leftIdx]);
			--leftIdx;
		}
		else
		{
			nearestElements.emplace_back(vec[rightIdx]);
			++rightIdx;
		}
	}

	return nearestElements;
}

int main()
{
	std::vector<int> vec{ 1, 2, 4, 15, 110, 111, 114, 115 };

	auto output = GetKNearestElements(1, 3, vec);
	for (const int i : output)
	{
		std::cout << i << " ";
	}

	std::cin.get();
	return 0;
}