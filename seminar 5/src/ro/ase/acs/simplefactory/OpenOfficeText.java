package ro.ase.acs.simplefactory;

public class OpenOfficeText implements Document{

	private String name = "newTextDocument";
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public void open() {
		// TODO Auto-generated method stub
		System.out.println(String.format("Opening file %s.odt...", name));
	}

}
