package ro.ase.java;

import ro.ase.java.thread.ShoppingUtils;
import ro.ase.java.thread.ShoppingUtilsSync;
import ro.ase.java.thread.ThreadClass;
import ro.ase.java.thread.ThreadRunnable;

public class Application {
	public static void main(String[] args) {
		ThreadClass tc1 = new ThreadClass("Thread 1");
		ThreadClass tc2 = new ThreadClass("Thread 2");
		
		tc1.start();
		tc2.start();
		
		ThreadRunnable tr1 = new ThreadRunnable();
		Thread t1 = new Thread(tr1, "Thread runnable 1");
		Thread t2 = new Thread(tr1, "Thread runnable 2");
		
		t1.start();
		t2.start();
		
		//pt ca in interfata ThreadRunnable ai doar o metoda abstracta poti scrie si asa:
		Runnable r1 = new Runnable() {
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				System.out.println("Executing thread: " + Thread.currentThread().getName());
			}
		};
		
		Thread t3 = new Thread(r1, "Annonymus Runnable 1");
		Thread t4 = new Thread(r1, "Annonymus Runnable 2");
		
		t3.start();
		t4.start();
		
		//Acelasi lucru, dar folosind lambda
		Runnable r2 = () -> {
			System.out.println("Executing thread: "+ Thread.currentThread().getName());
		};
		
		Thread t5 = new Thread(r2, "Lambda Runnable 1");
		Thread t6 = new Thread(r2, "Lambda Runnable 2");
		
		t5.start();
		t6.start();
		
		ShoppingUtils utils = new ShoppingUtils(200);
		Thread t7 = new Thread(utils, "Wife");
		Thread t8 = new Thread(utils, "Husband");
		
		t7.start();
		t8.start();
		
		/*
		ShoppingUtilsSync utilSync = new ShoppingUtilsSync(50);
		Thread t9 = new Thread(utilSync, "WifeSync");
		Thread t10 = new Thread(utilSync, "HusbandSync");
		
		t9.start();
		t10.start();
		*/
	}
}
