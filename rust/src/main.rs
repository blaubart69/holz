// 6x400 = 2400

// 2x100
// 2x156
// 4x171
// 4x146
// 2x71  = 1922

const STOCK_LEN : u16 = 400;

fn print_one_line(x : &[u16]) {
    let mut l = 0;

    for &i in x {
        if l + i < STOCK_LEN {
            l += i;
            print!(" {}", i);
        }
        else {
            l = i;
            print!(", {}", i);
        }
    }
    print!("\n");

}

fn sort_numbers_to_string(pieces : &mut Vec<u16>, tmp : &mut String) {
    tmp.clear();
    pieces.sort();
    
    for p in pieces {
        use std::fmt::Write;
        write!(tmp, " {}", p);
    }
}

fn print_sorted(x : &[u16]) {
    let mut l = 0;

    //let mut _v = Vec::new();
    static mut V : Vec<u16> = Vec::new();
    static mut S : Vec<String> = Vec::new();
    static mut TMP_STRING : String = String::new();

    for &i in x {
        if l + i < STOCK_LEN {
            l += i;
            V.push(i);
        }
        else {
            sort_numbers_to_string(&mut V, &mut TMP_STRING);
            S.push(TMP_STRING.chars().skip(1).collect::<String>());
            V.clear();
            
            l = i;
            V.push(i);
        }
    }

    sort_numbers_to_string(&mut V, &mut TMP_STRING);
    S.push(TMP_STRING.chars().skip(1).collect::<String>());

    S.sort();
    println!("{}", S.join(","));

}

fn cut(x : &[u16]) -> usize {
    
    let mut l = 0;
    let mut n = 0;
    
    for &i in x {
        if l + i < STOCK_LEN {
            l += i
        }
        else {
            n += 1;
            l = i;
        }
    }

    return n;
}

fn perm( n : usize, x : &mut [u16]) {

    if n == (x.len()-1)  {
        if cut(x) == 4 {
            //print_one_line(x);
            print_sorted(x);
        }
    
    }
    else {
        perm(n+1, x);
        for i in n+1..x.len() {
            if x[n] == x[i] { // not all but many
                continue;
            } 
            else {
                x.swap(n,i);
                perm(n+1, x);
                x.swap(n,i);
            }
        }
    }

}

fn main() {
    let mut x : Vec<u16> = vec![
        100, 100
        , 156, 156
        , 171, 171, 171, 171
        , 146, 146, 146, 146
        ,  71,  71 ];

    perm( 0, &mut x[..] );
}
