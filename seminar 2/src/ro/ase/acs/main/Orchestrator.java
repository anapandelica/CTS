package ro.ase.acs.main;

import ro.ase.acs.contracts.Readable;
import ro.ase.acs.contracts.Writeable;

public class Orchestrator {

	private Readable reader;
	private Writeable writer;
	
	public Orchestrator(Readable reader, Writeable writer) {
		this.reader = reader;
		this.writer = writer;
	}
	
	public Orchestrator(Object contract, Object implementation) {
		this.reader = (Readable)contract;
		this.writer = (Writeable)implementation;
		// TODO Auto-generated constructor stub
	}

	public void execute() {
		writer.print(reader.read());
	}
	
}
