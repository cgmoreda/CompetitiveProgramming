class Solution
{
 public:
	string reverseVowels(string s)
	{
		string v;
		for (auto& i : s)
			if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ||
				i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
				v.push_back(i);
		for (auto& i : s)
			if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ||
				i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
				i = v.back(), v.pop_back();

		return s;
	}
};