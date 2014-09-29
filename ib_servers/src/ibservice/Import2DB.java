package ibservice;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

public class Import2DB {

	/**
	 * @param args
	 * @throws ClassNotFoundException 
	 * @throws SQLException 
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws Exception {
		HSSFWorkbook wb=new HSSFWorkbook(Import2DB.class.getResourceAsStream("SCR.xls"));
		HSSFSheet sheet=wb.getSheetAt(0);
		HSSFRow row=sheet.getRow(0);
		StringBuilder sb=new StringBuilder();
		sb.append("create table scr_report (");
		for(int i=0;i<row.getLastCellNum();i++){
			HSSFCell cell=row.getCell(i);
			sb.append(cell.getStringCellValue()).append(" VARCHAR(128),");
		}
		System.out.println(sb.toString().substring(0, sb.length()-1));
	}

}
