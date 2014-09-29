package ibservice.servlet;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.sf.json.JSONObject;

public class ChartServlet extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doPost(request, response);
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String type=request.getParameter("type");
		Map<String,Object> data=new HashMap<String, Object>();
		
		Map<String,Object> y_legend=new HashMap<String, Object>();
		y_legend.put("text", type);
		y_legend.put("style", "{color: #736AFF;}");
		data.put("y_legend", y_legend);
		
		Map<String,Object> x_axis=new HashMap<String, Object>();
		Map<String,Object> labels=new HashMap<String, Object>();
		x_axis.put("labels", labels);
		labels.put("rotate", "vertical");
		data.put("x_axis", x_axis);
		
		Map<String,Object> y_axis=new HashMap<String, Object>();
		y_axis.put("max", 100);
		y_axis.put("steps", 10);
		data.put("y_axis", y_axis);
		
		List<Object> elements=new ArrayList<Object>();
		data.put("elements", elements);
		
		String sql="select * from cso_report";
		if("scr".equals(type)){
			sql="select * from scr_report";
		}
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
    		Connection conn=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl","ta4_1","ta4_1");
    		Statement stmt=conn.createStatement();
    		ResultSet rs=stmt.executeQuery(sql);
    		System.out.println("sql:::"+sql);
    		List<Integer> data1=new ArrayList<Integer>();
    		List<Integer> data2=new ArrayList<Integer>();
    		List<String> labels_data=new ArrayList<String>();
    		while(rs.next()){
    			labels_data.add(rs.getString("YEAR")+" "+rs.getString("FW"));
    			if("scr".equals(type)){
    				data1.add(rs.getInt("NEW_OPENED_SCR"));
        			data2.add(rs.getInt("OPENED_SCR"));
    			}else{
    				data1.add(rs.getInt("NEW_OPENED_CSO"));
        			data2.add(rs.getInt("OPENED_CSO"));
    			}
    		}
    		rs.close();
    		stmt.close();
    		conn.close();
    		labels.put("labels", labels_data);
    		Map<String,Object> dataMap1=new HashMap<String, Object>();
    		Map<String,Object> dataMap2=new HashMap<String, Object>();
    		dataMap1.put("type", "line");
    		dataMap2.put("type", "line");
    		
    		dataMap1.put("colour", "#736AFF");
    		dataMap2.put("colour", "#FFCC00");
    		
    		dataMap1.put("text", "NEW OPEN");
    		dataMap2.put("text", "OPEN");
    		
    		dataMap1.put("values", data1);
    		dataMap2.put("values", data2);
    		
    		elements.add(dataMap1);
    		elements.add(dataMap2);
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		response.getWriter().write(JSONObject.fromObject(data).toString());
		response.getWriter().flush();
	}

}
