use std::io;

fn read_int() -> u32 {
    let mut tmp = String::new();
    io::stdin()
        .read_line(&mut tmp)
        .expect("Could not read line");

    tmp.trim()
        .parse::<u32>()
        .expect("Could not parse to u32")
}

fn solve() {
    let mut v = read_int();

    if v < 102 {
        println!("NO");
        return;
    }

    let mut digits: Vec<u32> = Vec::new();
    while v != 0 {
        digits.push(v % 10);
        v /= 10;
    }

    // for e in &digits {
        // print!("{} ", e);
    // }

    let mut s = 1;
    for i in 0..(&digits.len() - 2) {
        v += s * digits[i as usize];
        s *= 10;
    }

    // println!("{v}");

    if v * 10 < s {
        println!("NO");
        return;
    }

    let b = digits[digits.len() - 1] * 10 + digits[digits.len() - 2];
    // println!("{b}");

    if b != 10 {
        println!("NO");
        return;
    }

    println!("YES");
}

fn main() {
    let mut t: u32 = read_int();

    while t != 0 {
        solve();

        t -= 1;
    }
}
