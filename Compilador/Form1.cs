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

namespace Compilador
{
    public partial class Form1 : Form
    {
        CompilerCore.Manager CompilerCore;
        bool textChanged;
        bool alreadyExist;
        string openPath;
        string savePath;
        SaveFileDialog saveDialog;
        OpenFileDialog openDialog;

        public Form1()
        {
            InitializeComponent();
            CompilerCore = new CompilerCore.Manager();
            textChanged = false;
            alreadyExist = false;
            saveDialog = new SaveFileDialog();
            openDialog = new OpenFileDialog();
        }

        private void textSrc_TextChanged(object sender, EventArgs e)
        {
            textChanged = true;
        }

        private void compileProgramToolStripMenuItem_Click(object sender, EventArgs e)
        {
            String[] complationDetails = CompilerCore.compileProgram(textSrc.Text);
            textOutput.Lines = complationDetails;
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
    }
}
