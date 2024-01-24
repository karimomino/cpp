#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iostream>

class PmergeMe {
public:
    template <typename Container>
    static double sort(Container &sequence)
    {
        std::clock_t start = std::clock();
        startSort(sequence);
        std::clock_t end = std::clock();
        double elapsed = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
        return elapsed;
    }

private:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &rhs);
    PmergeMe &operator=(const PmergeMe &rhs);

    template <typename Container>
    static void stepOneTwo(Container &sequence, Container& bigger, Container& smaller, std::vector< std::pair<int,int> >& pairs) {
        int stored = -1;
            if ((sequence.size() % 2) != 0) {
                stored = sequence.back();
                sequence.pop_back();
            }
            for (unsigned long i = 0; i < sequence.size(); i += 2)
            {
                if (sequence[i] < sequence[i + 1])
                    pairs.push_back( std::make_pair(sequence[i], sequence[i + 1]));
                else
                    pairs.push_back( std::make_pair(sequence[i + 1], sequence[i]));
            }

            for (unsigned long i = 0; i < pairs.size(); i++)
            {
                smaller.push_back(pairs[i].first);
                bigger.push_back(pairs[i].second);
            }
            if (stored != -1)
                smaller.push_back(stored);
            
        
    }

    template <typename Container>
    static void merge(Container& sequence, int start, int mid, int end) {
        int leftSize = mid - start + 1;
        int rightSize = end - mid;

        Container left(sequence.begin() + start, sequence.begin() + mid + 1);
        Container right(sequence.begin() + mid + 1, sequence.begin() + end + 1);

        int i = 0, j = 0, k = start;

        while (i < leftSize && j < rightSize) {
            if (left[i] <= right[j]) {
                sequence[k++] = left[i++];
            } else {
                sequence[k++] = right[j++];
            }
        }

        while (i < leftSize) {
            sequence[k++] = left[i++];
        }

        while (j < rightSize) {
            sequence[k++] = right[j++];
        }
    }

    
    template <typename Container>
    static void mergeSort(Container& sequence, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(sequence, start, mid);
            mergeSort(sequence, mid + 1, end);
            merge(sequence, start, mid, end);
        }
    }

    template <typename Container>
    static void stepThree(Container& sequence) {
        mergeSort(sequence, 0 , sequence.size() - 1);
    }
    
    
    template <typename Container>
    static void stepFour(Container& bigger, Container& smaller, std::vector< std::pair<int,int> > pairs) {

        std::vector< std::pair<int,int> >::const_iterator p_it = pairs.begin();
        typename Container::iterator b_it = bigger.begin();
        typename Container::iterator s_it = smaller.begin();

        for ( ; p_it != pairs.end(); p_it++)
        {
            if (p_it->second == *b_it) {
                bigger.insert(b_it, p_it->first);
                smaller.erase(std::find(s_it , smaller.end(), p_it->first));
                break; 
            }

        }

    }

    template <typename Container>
    static void stepFive(Container& bigger, Container& smaller) {
        std::vector< std::pair<int,int> > unsorted_pairs;
        typename Container::iterator s_it = smaller.begin();

        for (unsigned long i = 0; i + 1 < smaller.size(); i += 2){
            unsorted_pairs.push_back(std::make_pair(smaller[i + 1] , smaller[i]));
            smaller.erase(s_it , s_it + 2);
            s_it = smaller.begin();
        }
        for (unsigned long i = 0; i < unsorted_pairs.size(); i++){
            smaller.insert(s_it , unsorted_pairs[i].second);
            smaller.insert(s_it , unsorted_pairs[i].first);
        }
        s_it = smaller.begin();
        for (; s_it != smaller.end(); ++s_it) {
            typename Container::iterator insertPos = std::lower_bound(bigger.begin(), bigger.end(), *s_it);
            bigger.insert(insertPos, *s_it);
        }
        smaller.clear();
    }

    template <typename Container>
    static void startSort(Container &sequence)
    {
        if (!sequence.empty())
        {
            Container bigger;
            Container smaller;
            std::vector< std::pair<int,int> > pairs;

            stepOneTwo(sequence, bigger, smaller, pairs);
            stepThree(bigger);
            stepFour(bigger, smaller, pairs);
            stepFive(bigger , smaller);
            sequence.clear();
            sequence.insert(sequence.end(), bigger.begin() , bigger.end());
        }
    }

    template <typename Container>
    static void insertionSort(Container &vec, int start, int end)
    {
        for (int i = start + 1; i <= end; ++i)
        {
            int key = vec[i];
            int j = i - 1;

            while (j >= start && vec[j] > key)
            {
                vec[j + 1] = vec[j];
                --j;
            }

            vec[j + 1] = key;
        }
    }

    template <typename Container>
    static void binaryInsertionSort(Container &vec, int start, int end)
    {
        for (int i = start + 1; i <= end; ++i)
        {
            int key = vec[i];
            int left = start;
            int right = i;

            while (left < right)
            {
                int mid = (left + right) / 2;

                if (key < vec[mid])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }

            for (int j = i; j > left; --j)
            {
                vec[j] = vec[j - 1];
            }

            vec[left] = key;
        }
    }

};

#endif
