# HackerRank

Solutions to algorithm problems from [HackerRank](https://www.hackerrank.com) in JavaScript and C.

# Hints
- Allocating values to array after `malloc`/`calloc`
```c
int* arr = calloc(5, sizeof(int));
arr = (int[]){1, 2, 3, 4, 5};
```

# Common issue

There is a common bug in the C boilerplate code on [HackerRank](https://www.hackerrank.com) causing several of the test cases to fail even if your code is running correctly. Encountered (so far) in:
- [Equality in an array](https://www.hackerrank.com/challenges/equality-in-a-array/problem)
- [Minimum distances](https://www.hackerrank.com/challenges/minimum-distances/problem)
- [Lisa's workbook](https://www.hackerrank.com/challenges/lisa-workbook/problem)
- [Flatland space stations](https://www.hackerrank.com/challenges/flatland-space-stations/problem)
- [Fair rations](https://www.hackerrank.com/challenges/fair-rations/problem)

Please use `scanf()` in the boilerplate code for the `main()` method to bypass the issue. For example:
```c
int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n, c_count;

    scanf("%d", &n);
    scanf("%d", &c_count);

    int *c = malloc(c_count * sizeof(int));

    for (int j = 0; j < n; j++) {
      scanf("%d", &c[j]);
    }

    int result = flatlandSpaceStations(n, c_count, c);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}
```

For [Fair rations](https://www.hackerrank.com/challenges/fair-rations/problem) in addition to the above fix, had to do the following in `main()` since a `char*` cannot be returned from an `int` method.

```c
    if(result == INT_MIN){
        fprintf(fptr, "NO\n");
    } else {
    fprintf(fptr, "%d\n", result);
    }
```
