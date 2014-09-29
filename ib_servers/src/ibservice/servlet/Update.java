package ibservice.servlet;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.Iterator;
import java.util.Locale;

import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

public class Update {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws Exception {
		Class.forName("oracle.jdbc.driver.OracleDriver");
		Connection conn=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl","ta4_1","ta4_1");
		Statement stmt=conn.createStatement();
		HSSFWorkbook wb=new HSSFWorkbook(new FileInputStream("C:\\pgh\\Closed_CSO.xls"));
		HSSFSheet sheet=wb.getSheetAt(0);
		Iterator iterator=sheet.rowIterator();
		iterator.next();
		while(iterator.hasNext()){
			HSSFRow row=(HSSFRow)iterator.next();
			String id=row.getCell(0).getStringCellValue();
			String open=row.getCell(4).getStringCellValue();
			String close=row.getCell(5).getStringCellValue();
			String milestone=row.getCell(6).getStringCellValue();
			System.out.println(new SimpleDateFormat("yyyy-MM-dd").format(new SimpleDateFormat("MMM dd, yyyy",Locale.ENGLISH).parse(open)));
			String sql1="insert into CSO(csonumber,csostartdate,closedate,stauts) values('"+id+"','"+new SimpleDateFormat("yyyy-MM-dd").format(new SimpleDateFormat("MMM dd, yyyy",Locale.ENGLISH).parse(open))+"',to_date('"+new SimpleDateFormat("yyyy-MM-dd").format(new SimpleDateFormat("MMM dd, yyyy",Locale.ENGLISH).parse(close))+"','yyyy-mm-dd'),'"+milestone+"')";
			String sql="update CSO set milestonestatus='"+milestone+"',closedate=to_date('"+new SimpleDateFormat("yyyy-mm-dd").format(new SimpleDateFormat("MMM dd, yyyy",Locale.ENGLISH).parse(close))+"','yyyy-mm-dd') where csonumber='"+id+"'";
			System.out.println(sql1);
			stmt.executeUpdate(sql1);
		}
		stmt.close();
		conn.close();
	}

}
