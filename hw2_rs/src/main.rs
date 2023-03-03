use std::io;

fn main() {
    let mut input = String::new();

    loop {
        io::stdin().read_line(&mut input).unwrap();
        let mut input_str = input.trim().split(' ');

        let a_str = input_str.next().unwrap();
        let a: usize = a_str.parse().unwrap();

        let b_str = input_str.next().unwrap();
        let b: usize = b_str.parse().unwrap();

        let c_str = input_str.next().unwrap();
        let c: usize = c_str.parse().unwrap();

        let d_str = input_str.next().unwrap();
        let d: usize = d_str.parse().unwrap();
        
        input.clear();

        if a+b+c+d == 0 {
            return;
        }

        if a==c && b>d {
            println!("{}", 1380+(60-b+d));
            continue;
        }
        
        let hour = if c<a {
            24-a+c
        } else {
            c-a
        };

        let min = if d<b {
            60-b+d
        } else {
            d-b
        };

        println!("{}", hour*60+min);
    }
    

}