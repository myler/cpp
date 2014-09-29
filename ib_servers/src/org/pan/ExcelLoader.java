package org.pan;

import org.apache.poi.openxml4j.exceptions.InvalidFormatException;
import org.apache.poi.ss.usermodel.*;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;

/**
 * Created by yigli on 14-6-23.
 */
public class ExcelLoader {

    private Workbook workbook = null;

    public ExcelLoader(String excel){

        InputStream inputStream = null;
        try {
            inputStream = new FileInputStream(excel);
            workbook = WorkbookFactory.create(inputStream);

        } catch (Exception e) {
            throw new RuntimeException("Init Excel Loader Error",e);
        }finally {
            if(inputStream != null){
                try {
                    inputStream.close();
                } catch (IOException e) {
                    throw new RuntimeException("Close InputStream Error",e);
                }
            }
        }

    }


    public List<List<String>> loadData(int sheetNumber){
        Sheet sheet = workbook.getSheetAt(sheetNumber);

        if(sheet == null ){
            return Collections.emptyList();
        }

        List<List<String>> ret = new ArrayList<List<String>>(sheet.getTopRow());

        for(Row row:sheet) {
            List<String> rowlist = new ArrayList<String>();

            for(Cell cell : row){
                rowlist.add(cell.toString());
            }

            ret.add(rowlist);

        }

        return ret;
    }


    public static void main(String[] args){

        ExcelLoader loader = new ExcelLoader("/home/myl/ib_server/5480614Rev3.xlsx");

        for(List<String> list: loader.loadData(0).subList(7,18)){

            System.out.println(list.toString());
        }
    }



}
