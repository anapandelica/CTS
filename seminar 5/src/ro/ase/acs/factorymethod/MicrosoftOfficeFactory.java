package ro.ase.acs.factorymethod;

import ro.ase.acs.simplefactory.Document;
import ro.ase.acs.simplefactory.ExcelDocument;
import ro.ase.acs.simplefactory.NoSuchDocumentException;
import ro.ase.acs.simplefactory.WordDocument;

public class MicrosoftOfficeFactory implements AbstractDocumentFactory{

	@Override
	public Document getDocument(FileType type, String fileName) throws NoSuchDocumentException {
		// TODO Auto-generated method stub
		if(type == FileType.DOCUMENT) {
			return new WordDocument(fileName);
		} else if(type == FileType.SPREADSHEET) {
			return new ExcelDocument(fileName);
		} throw new NoSuchDocumentException();
	}
}
