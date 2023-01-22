use std::io;

fn main(){
    let mut input_line = String::new();
    io::stdin()
        .read_line(&mut input_line)
        .expect("failed to read line.");
    
    let in: usize = input_line.trim().parse().expect("cannot convert to uint.");
                        
    for i in (0..in) {
        let mut sum = 0;
        
    }
}

