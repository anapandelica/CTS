package ro.ase.acs.main;

import ro.ase.acs.simplefactory.Document;
import ro.ase.acs.simplefactory.DocumentFactory;
import ro.ase.acs.simplefactory.DocumentType;
import ro.ase.acs.simplefactory.NoSuchDocumentException;
import ro.ase.acs.simplefactory.OpenOfficeSpreadsheet;

public class Main {

	public static void main(String[] args) {
		
		DocumentFactory documentFactory = new DocumentFactory();
		try {
			Document document = documentFactory.getDocument(
					DocumentType.OPENOFFICE_SPREADSHEET, "Doc"); //oricum ignora numele
			document.open();
		} catch (NoSuchDocumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
	}

}
