package ro.ase.java.thread;

//Cand folosesti threaduri trebuie sa extinzi cu Thread clasa respectiva
public class ThreadClass extends Thread{
	private String name;
	
	public ThreadClass(String name) {
		super(name);
		this.name = name;
	}
	//nu e generata de pc
	@Override
	public void run() {
		System.out.println("Executing thread: " + this.name);
	}
}
