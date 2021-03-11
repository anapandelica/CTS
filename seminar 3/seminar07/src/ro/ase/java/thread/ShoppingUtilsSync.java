package ro.ase.java.thread;

public class ShoppingUtilsSync implements Runnable{
	private double balance;
	private Object lock = new Object();
	
	public ShoppingUtilsSync(double balance) {
		this.balance = balance;
	}

	public void withdraw(double amount) {
		synchronized(lock) {
		if(this.balance >= amount) {
			try {
				Thread.currentThread().sleep(200);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			this.balance -= amount;
			System.out.println(Thread.currentThread().getName()+ " made a transaction. New balance is: " + this.balance);
		}
	}
}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i = 0; i < 100; i++) {
			//am pus chestia aia in try ca sa asigure ca nu o sa acceseze doar un thread balance ul
			try {
				Thread.currentThread().sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			withdraw(5);
		}
	}
	
	
}
