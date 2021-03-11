package ro.ase.java.thread;

public class ThreadRunnable implements Runnable {

	@Override
	public void run() {
		// TODO Auto-generated method stub
		System.out.println("Exectuting thread: " + Thread.currentThread().getName());
	}

}
