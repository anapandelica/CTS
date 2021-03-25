package ro.ase.acs.factorymethod;

import ro.ase.acs.simplefactory.Document;
import ro.ase.acs.simplefactory.NoSuchDocumentException;

public interface AbstractDocumentFactory {

	public Document getDocument(FileType type, String fileName) throws NoSuchDocumentException;
}
