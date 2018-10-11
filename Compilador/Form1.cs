using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Diagnostics;
using System.Management;

namespace Compilador
{
    public partial class Form1 : Form
    {
       
        bool textChanged;
        bool alreadyExist;
        string openPath;
        string savePath;
        SaveFileDialog saveDialog;
        OpenFileDialog openDialog;
        dynamic compillerDll;
        CompilerCore.Manager CompilerCore;

        public Form1()
        {
            InitializeComponent();
            CompilerCore = new CompilerCore.Manager();
            textChanged = false;
            alreadyExist = false;            
            saveDialog = new SaveFileDialog();
            openDialog = new OpenFileDialog();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string dllPath = "";

            if (System.Environment.Is64BitProcess)
            {
                if (isDebuggable())
                {
                    dllPath = Path.Combine(getPath(), "x64\\Debug");
                }
                else
                {
                    dllPath = Path.Combine(getPath(), "x64\\Release");
                }
            }
            else
            {
                if (isDebuggable())
                {
                    dllPath = Path.Combine(getPath(), "x86\\Debug");
                }
                else
                {
                    dllPath = Path.Combine(getPath(), "x86\\Release");
                }
            }

            dllPath = Path.Combine(dllPath, "CompilerCore.dll");
            var DLL = Assembly.LoadFile(dllPath);
            var DLLType = DLL.GetType("CompilerCore.Manager");
            compillerDll = Activator.CreateInstance(DLLType);
            if (compillerDll == null)
            {
                
            }
        }

        private bool isDebuggable()
        {
            object[] attribs = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(DebuggableAttribute), true);

            if ((attribs != null) && (attribs.Length == 1))
            {
                DebuggableAttribute attribute = attribs[0] as DebuggableAttribute;

                if (attribute.IsJITOptimizerDisabled && attribute.IsJITTrackingEnabled)
                {
                    return true;
                }
            }
            return false;
        }

        private void textSrc_TextChanged(object sender, EventArgs e)
        {
            textChanged = true;
        }

        private void compileProgramToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textOutput.Clear();
            Tokens.Rows.Clear();
            Tokens.Refresh();
            String[] compilationDetails = CompilerCore.compileProgram(textSrc.Text);
            int a = Array.FindIndex(compilationDetails, m => m == "@");
            String[] lexErrors = new string[a];
            Array.Copy(compilationDetails,lexErrors,a);
            textOutput.Lines = lexErrors;
            String[] lexTokens = new string[compilationDetails.Length - a - 1];
            Array.Copy(compilationDetails, a + 1, lexTokens, 0, lexTokens.Length);
            object[] obj = new object[lexTokens.Length];
            char splitter = '\t';
            for (int i = 0; i < lexTokens.Length; i++)
            {
                obj[i] = new string[3];
                obj[i] = lexTokens[i].Split(splitter);
            }
            foreach (string[] stringer in obj ) //xd
            {
                Tokens.Rows.Add(stringer);
            }


        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textChanged)
            {
                DialogResult result1 = MessageBox.Show("      Deseas Guardar?", "", MessageBoxButtons.YesNo);
                if (result1 == DialogResult.Yes)
                {
                    if(alreadyExist)
                    {
                        saveToolStripMenuItem_Click(sender, e);
                        textSrc.Clear();
                    }
                    else
                    {
                         saveAsToolStripMenuItem_Click(sender, e);
                        textSrc.Clear();                 
                    }
                }

                else
                {
                    textSrc.Clear();
                    
                }
            }
            else
            {
                textSrc.Clear();
                
            }
            alreadyExist = false;
            textChanged = false;
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            alreadyExist = true;

            if (textChanged)
            {
                DialogResult result1 = MessageBox.Show("      Deseas Guardar?", "", MessageBoxButtons.YesNo);
                if (result1 == DialogResult.Yes)
                {
                    saveAsToolStripMenuItem_Click(sender, e);
                  if (openDialog.ShowDialog() == DialogResult.OK)
                  {
                        openPath = openDialog.FileName;
                        textSrc.Lines = File.ReadAllLines(openPath);
                       
                  }

                }
                else
                {
                    if (openDialog.ShowDialog() == DialogResult.OK)
                    {
                        openPath = openDialog.FileName;
                        textSrc.Lines = File.ReadAllLines(openPath);         
                    } 
                }

            }
            else
            {
                if (openDialog.ShowDialog() == DialogResult.OK)
                {
                    openPath = openDialog.FileName;
                    textSrc.Lines = File.ReadAllLines(openPath);
                }
            }
            textChanged = false;

        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (alreadyExist)
            {
                File.WriteAllLines(openPath, textSrc.Lines); 
            }
            else
            {
                saveAsToolStripMenuItem_Click(sender, e);
            }

            textChanged = false;
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {

            if (saveDialog.ShowDialog() == DialogResult.OK)
            {
                savePath = saveDialog.FileName;
                File.WriteAllLines(savePath, textSrc.Lines);
               
            }
            textChanged = false;
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private string getPath()
        {
            string FullPath = Application.StartupPath;

            for (int i = 0; i < 4; i++)
            {
                FullPath = Directory.GetParent(FullPath).ToString();
            }
            FullPath = Path.Combine(FullPath, "CompilerCore\\Binaries\\");
            return FullPath;
        }

    }
}
