package ro.ase.acs.factorymethod;

import ro.ase.acs.simplefactory.Document;
import ro.ase.acs.simplefactory.NoSuchDocumentException;

public class Main {

	public static void main(String[] args) {
		
		AbstractDocumentFactory documentFactory = new OpenOfficeFactory();
		try {
			Document document = documentFactory.getDocument(FileType.SPREADSHEET, "students");
			document.open();
		} catch (NoSuchDocumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
