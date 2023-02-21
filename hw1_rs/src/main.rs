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
        
        let mut a = str2u64(input_str.next().unwrap());
        let b = str2u64(input_str.next().unwrap());
        let c = str2u64(input_str.next().unwrap());
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

fn str2u64(var_str: &str) -> u64 {
    let var: u64 = var_str.parse().unwrap();
    var
}
