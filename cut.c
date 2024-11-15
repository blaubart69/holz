#include <stdio.h>
#include <string.h>

// 6x400 = 2400

// 2x100
// 2x156
// 4x171
// 4x146
// 2x71  = 1922

#define STOCK_CNT 5
#define STOCK_LEN 400

unsigned long long int _k[ 14 ];

static void print( int *x, int size ) {

    int n = 0, l = 0, i;

    printf( "0:" );

    for ( i = 0; i < size; i++ ) {
        if (( l + x[ i ] ) < STOCK_LEN ) {
            l += x[ i ];
            printf( " %3d", x[ i ] );
        } else {
            n++;
            printf( "\n%d: %3d", n, x[ i ] );
            l = x[ i ];
        } /* endif */
    } /* endfor */
    printf( "\n\n" );
}

static void print2( int *x, int size ) {

    int n = 0, l = 0, i;

    //printf( "0:" );

    for ( i = 0; i < size; i++ ) {
        if (( l + x[ i ] ) < STOCK_LEN ) {
            l += x[ i ];
            printf( " %3d", x[ i ] );
        } else {
            printf( ", %3d", x[ i ] );
            l = x[ i ];
        } /* endif */
    } /* endfor */
    printf( "\n" );
}

static int cut( int *x, int size ) {

    int n = 0, l = 0, i;

    for ( i = 0; i < size; i++ ) {
        if (( l + x[ i ] ) < STOCK_LEN ) {
            l += x[ i ];
        } else {
            n++;
            l = x[ i ];
        } /* endif */
    } /* endfor */

if ( n == 4 ) {
    print2( x, size );
    //getch();
}

    return n;    
}

static void perm( int n, int size, int *x ) {

    int i, tmp;

    if ( n == ( size - 1 )) {
        _k[ cut( x, size ) ]++;
    } else {
        perm( n + 1, size, x );
        for ( i = n + 1; i < size; i++ ) {
            if ( x[ n ] == x[ i ] ) continue; // not all but many
            tmp = x[ n ]; x[ n ] = x[ i ]; x[ i ] = tmp;
            perm( n + 1, size, x );
            tmp = x[ n ]; x[ n ] = x[ i ]; x[ i ] = tmp;
        } /* endfor */
    } /* endif */
}

int main( int agrc, char *argv[] ) {

    int x[ 14 ] = { 100, 100
                  , 156, 156
                  , 171, 171, 171, 171
                  , 146, 146, 146, 146
                  ,  71,  71
                  };
    int i;

    memset( _k, 0, sizeof( _k ));

    perm( 0, 14, x );

    for ( i = 0; i < 14; i++ ) {
        //printf( "%2d %14I64u\n", i, _k[ i ] );
        printf( "%2d %14llu\n", i, _k[ i ] );
    } /* endfor */
    
    return 0;
}
