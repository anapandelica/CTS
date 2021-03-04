package ro.ase.acs.main;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Scanner;

import ro.ase.acs.contracts.Readable;
import ro.ase.acs.contracts.Writeable;
import ro.ase.acs.readers.Reader;
import ro.ase.acs.writers.ConsoleWriter;
import ro.ase.acs.writers.FileWriter;

public class Main {

	static Class c1 = IoC.resolve(Readable.class);
	public static void main(String[] args) {
		IoC ioc = new IoC();
		
		
		ioc.register(Readable.class, Reader.class);
		ioc.register(Writeable.class, ConsoleWriter.class);
		
		Object reader = null;
		try {
			reader = ioc.resolve(Readable.class).getConstructor().newInstance();
		} catch (InstantiationException | IllegalAccessException | IllegalArgumentException | InvocationTargetException
				| NoSuchMethodException | SecurityException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		Object writer = null;
		try {
			writer = ioc.resolve(Writeable.class).getConstructor().newInstance();
		} catch (InstantiationException | IllegalAccessException | IllegalArgumentException | InvocationTargetException
				| NoSuchMethodException | SecurityException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	
		Orchestrator orchestrator = new Orchestrator(reader, writer);
		orchestrator.execute();
				
	}
}
