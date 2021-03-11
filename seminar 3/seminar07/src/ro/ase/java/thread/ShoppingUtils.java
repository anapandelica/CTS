package ro.ase.java.thread;

public class ShoppingUtils implements Runnable{
	private double balance;
	
	public ShoppingUtils(double balance) {
		this.balance = balance;
	}
	
	public void withdraw(double amount) {
		if(this.balance >= amount) {
			try {
			Thread.currentThread().sleep(300);
			}
			catch(InterruptedException e) {
				//TODO Auto-generated catch block
				e.printStackTrace();
			}
			this.balance -= amount;
			System.out.println(Thread.currentThread().getName() + " made a transaction. Balance left: " + this.balance);
		}
		
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i = 0; i < 100; i++) {
			this.withdraw(5);
		}
	}
	
	
}
