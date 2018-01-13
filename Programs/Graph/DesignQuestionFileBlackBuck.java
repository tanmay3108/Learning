import java.util.HashMap;

class Filee
{
    private  static String fileContent;
    private static HashMap<String,String> fVsC;
    public  static String  getFileContent()
    {
        if(fileContent == null)
        {
            //File f = new File()
            //fileCotent = f.toString();
            System.out.println("It should be printed only once");
            fileContent = "FileContet";
        }

        return fileContent;
    }

    public static HashMap<String,String> getFilesContent()
    {
        if(fVsC == null)
        {
            System.out.println("Loading files");
            fVsC =  new HashMap<String,String>();
            fVsC.put("A","Hello");

        }
        return fVsC;

    }


}

public class FileAPI
{
   public static HashMap<String,String> fileNameVsContent = Filee.getFilesContent();
    public static String getFileContent()
    {

        return Filee.getFileContent();
    }
    public static String getFilesContent(String name)
    {
        return fileNameVsContent.get(name);
    }
    public static void main(String args[])
    {
        System.out.println(FileAPI.getFileContent());
        System.out.println(FileAPI.getFilesContent("A"));
    }
}



