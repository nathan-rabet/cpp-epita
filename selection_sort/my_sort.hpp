#ifndef MY_SORT_H
#define MY_SORT_H

template <class CONT>
void my_selection_sort(CONT begin, CONT end)
{
    for (CONT i = begin; i != end; i++)
    {
        CONT min = i;
        for (auto j = i; j != end; j++)
        {
            if (*j < *min)
                min = j;
        }
        auto tmp = *i;
        *i = *min;
        *min = tmp;
    }
}

#endif /* MY_SORT_H */
