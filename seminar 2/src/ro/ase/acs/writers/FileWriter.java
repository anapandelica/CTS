package ro.ase.acs.writers;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

import ro.ase.acs.contracts.Writeable;

public class FileWriter implements Writeable{

	@Override
	public void print(String message) {
		FileOutputStream fileOutputStream;
		OutputStreamWriter osWriter = null;
		try {
			fileOutputStream = new FileOutputStream("output.txt");
			osWriter = new OutputStreamWriter(fileOutputStream);
			osWriter.write(message);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally {
			if(osWriter != null) {
				try {
					osWriter.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
}
