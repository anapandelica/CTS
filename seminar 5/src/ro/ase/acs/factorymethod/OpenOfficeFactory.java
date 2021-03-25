package ro.ase.acs.factorymethod;

import ro.ase.acs.simplefactory.Document;

import ro.ase.acs.simplefactory.NoSuchDocumentException;
import ro.ase.acs.simplefactory.OpenOfficeSpreadsheet;
import ro.ase.acs.simplefactory.OpenOfficeText;

public class OpenOfficeFactory implements AbstractDocumentFactory{

	@Override
	public Document getDocument(FileType type, String fileName) throws NoSuchDocumentException {
		// TODO Auto-generated method stub
		if(type == FileType.DOCUMENT) {
			OpenOfficeText officeText = new OpenOfficeText();
			officeText.setName(fileName);
			return officeText;
		} else if(type ==  FileType.SPREADSHEET) {
			OpenOfficeSpreadsheet officeSpreadsheet = new OpenOfficeSpreadsheet();
			officeSpreadsheet.setName(fileName);
			return officeSpreadsheet;
		} throw new NoSuchDocumentException();
	}

}
