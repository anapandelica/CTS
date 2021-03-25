package ro.ase.acs.simplefactory;

public class ExcelDocument implements Document{

		private String name;
		
		public ExcelDocument(String name) {
			this.name = name;
		}

		@Override
		public void open() {
			// TODO Auto-generated method stub
			System.out.println(String.format("Opening file %s.xlsx...", this.name));
		}
		
}
