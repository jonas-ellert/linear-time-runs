## Linear Time Runs over General Ordered Alphabets

A run in a string ``S`` is a substring that is a maximal periodic substring. 
For example, the string ``bananatree`` contains exactly the runs ``S[2..6] = anana`` and ``S[9..10] = ee``.
The substring ``S[3..6] = nana`` is not a run; it is periodic, but not maximal because it is contained in the longer periodic substring ``S[2..6]``.
There are less than ``n`` runs in a string of length ``n``, and they can be computed in ``O(n)`` time using the runs algorithm by Bannai et al. (https://doi.org/10.1137/15M1011032).
The algorithm requires an integer alphabet that can be sorted in linear time.

In this repository we provide an improved ``C++`` implementation of the runs algorithm that achieves ``O(n)`` time even for *general ordered alphabets*.
A full description of the algorithm has been submitted to ICALP 2021. 
A pre-print version is available on arXiv: https://arxiv.org/abs/2102.08670.
**The documentation of the code has not been completed yet.**

### Using the algorithm

In order to use the algorithm you only have to include the header file ``runs.hpp`` in your project. 
It requires no external libraries and uses only standard ``C++`` features (apart from ``#pragma once``). 
The interface of the algorithm is very easy to use, as demonstrated in the file ``example.cpp``.
**In the current version, it is necessary that the input text starts and ends with a sentinel character that is smaller than all other characters in the text.**
We use the following type to store runs, where ``index_type`` defaults to ``uint32_t``:

```c++
template<typename index_type>
struct run_type {
    index_type start;
    index_type period;
    index_type length;
};
```

The result of the algorithm is an ``std::vector<run_type<index_type>>`` containing all runs, sorted by start position and period length.
If you want to process large inputs (``n >= 2^32``), then you have to explicitly specify a larger integer type by calling:

```c++
auto R = linear_time_runs::compute_all_runs<uint64_t>(...);
```

This will return the runs as an ``std::vector<run_type<uint64_t>>`` (of course you can use any other signed or unsigned integral type instead of ``uint64_t``).
If you have any questions or problems feel free to contact us.

### Licensing

This software is provided under the MIT license. For more information see the LICENSE file.

If you use our implementation in an academic setting, we kindly ask you to cite the following paper (this will be updated once a conference or pre-print version has been published):

```
Linear Time Runs over General Ordered Alphabets.
Jonas Ellert and Johannes Fischer.
CoRR abs/2102.08670 (https://arxiv.org/abs/2102.08670), 2021.
Submitted to ICALP 2021.
```
