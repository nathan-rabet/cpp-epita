template <class CONT>
void my_selection_sort(CONT begin, CONT end)
{
    for (CONT i = begin; i != end; i++)
    {
        CONT min = i;
        for (CONT j = i; j != end; j++)
        {
            if (*j < *min)
                min = j;
        }
        auto tmp = *i;
        *i = *min;
        *min = tmp;
    }
}
