use std::io;

fn main(){
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .unwrap();
    
    let n: u64 = input.trim().parse().unwrap();
    input.clear();
    for _ in 0..n {
        io::stdin()
            .read_line(&mut input)
            .unwrap();
        let mut input_str = input.trim().split(' ');
        
        let a_str = input_str.next().unwrap();
        let mut a: u64 = a_str.parse().unwrap();

        let b_str = input_str.next().unwrap();
        let  b: u64 = b_str.parse().unwrap();

        let c_str = input_str.next().unwrap();
        let  c: u64 = c_str.parse().unwrap();
        
        input.clear();

        let mut sum: u64 = 0;
        a += b;
        while a/c > 0 {
            sum += a/c;
            a = a%c + a/c;
        }
        println!("{}", sum);
    }
}

