#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace ir {
    using value_type = int;

    /// Negate all integer values in [first;last).
    void negate( value_type * first, value_type * last );
    /*!
     * \brief Copy the content of the range `[first;last)` to another range beginning at `d_first`.
     * \return An iterator point to the element past the last element copied from the source range.
     */
    value_type * copy( const value_type * , const value_type *, value_type* );

    /// Returns a pointer to the first occurrency of the smallest element the range.
    const value_type * min( const value_type *, const value_type * );

    /// Reverse the order of the elements in range `[first;last)`.
    void reverse( value_type *first, value_type*last );

    void scalar_multiplication(value_type *first,value_type *last,value_type scalar);

    value_type dot_product(value_type *a_first,value_type *a_last,value_type *b_frist);

    value_type *compact(value_type *first, value_type *last);

    value_type *unique(value_type *first,value_type *last);

    value_type *sort_marbles(value_type *first,value_type *last);

    void partition(value_type *first,value_type *last, value_type *pivot);

    void rotate(value_type *first,value_type *n_first,value_type *last);
    
}
#endif
