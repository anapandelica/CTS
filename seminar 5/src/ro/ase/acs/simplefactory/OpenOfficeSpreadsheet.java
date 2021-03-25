package ro.ase.acs.simplefactory;

public class OpenOfficeSpreadsheet implements Document{

	
	private String name = "newSpreadsheet";
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public void open() {
		System.out.println(String.format("Opening file %s.ods..", name));
	}

	
}
