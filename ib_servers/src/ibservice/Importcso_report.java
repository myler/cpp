package ibservice;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.SQLException;

import org.dom4j.DocumentException;

import com.sunsheen.iims.file2db.DBManager;
import com.sunsheen.iims.file2db.URLFormatException;
import com.sunsheen.iims.file2db.execute.ExcelDataSource;

public class Importcso_report {

	/**
	 * @param args
	 * @throws ClassNotFoundException 
	 * @throws SQLException 
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws Exception {
		ExcelDataSource ds=new ExcelDataSource(Importcso_report.class.getResourceAsStream("scr_report.xls"));
		DBManager db = new DBManager();
		db.setDs(ds);
		try {
			db.insertIntoDabase(Importcso_report.class.getResourceAsStream("scr_report.xml"));
		} catch (IOException e) {
			e.printStackTrace();
		} catch (DocumentException e) {
			e.printStackTrace();
		} catch (URLFormatException e) {
			e.printStackTrace();
		}
	}

}
