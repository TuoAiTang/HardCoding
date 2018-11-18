int threeSumMulti(int* A, int ASize, int target) {
	long long int res = 0;
    int hm[101] = {0};
    for (int i = 0; i < ASize; ++i)
		hm[A[i]]++;
	for (int i = 0; i <= target / 3; ++i)
	{
		for (int j = i; j <= target /2; ++j)
		{
			int k = target - i - j;
			if(k > 100 || k < j) continue;
			if(i == j && j == k)
				res += hm[i] * (hm[i] - 1) * (hm[i] - 2) / 6;
			else if(i == j)
				res += hm[i] * (hm[i] - 1) / 2 * hm[k];
			else if(j == k)
				res += hm[j] * (hm[j] - 1) / 2 * hm[i];
			else
				res += hm[i] * hm[j] * hm[k];
		}
	}
	return res % 1000000007;
}