#pragma once
#pragma warning(disable: 4996)

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

}

#include <io.h>
#include <time.h>
//#include <thread>

namespace CLRproj {

	using namespace System::Runtime::InteropServices;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			av_register_all();

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnExit;
	protected:

	private: System::Windows::Forms::Button^  btnOpen;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  tbOpenFilePath;
	private: System::Windows::Forms::Button^  btnProcces;
	private: System::Windows::Forms::Button^  btnCancel;






	protected:

	private:

		AVFormatContext *pFormatCtx = NULL;
	private: System::Windows::Forms::RichTextBox^  rtbVideoInfo;
	private: System::Windows::Forms::ProgressBar^  pbProccess;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  comboBox1;




		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tbOpenFilePath = (gcnew System::Windows::Forms::TextBox());
			this->btnProcces = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->rtbVideoInfo = (gcnew System::Windows::Forms::RichTextBox());
			this->pbProccess = (gcnew System::Windows::Forms::ProgressBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(666, 364);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 0;
			this->btnExit->Text = L"Выход";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(666, 10);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(75, 23);
			this->btnOpen->TabIndex = 1;
			this->btnOpen->Text = L"Открыть";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// tbOpenFilePath
			// 
			this->tbOpenFilePath->Location = System::Drawing::Point(12, 12);
			this->tbOpenFilePath->Name = L"tbOpenFilePath";
			this->tbOpenFilePath->Size = System::Drawing::Size(648, 20);
			this->tbOpenFilePath->TabIndex = 2;
			// 
			// btnProcces
			// 
			this->btnProcces->Location = System::Drawing::Point(666, 37);
			this->btnProcces->Name = L"btnProcces";
			this->btnProcces->Size = System::Drawing::Size(75, 23);
			this->btnProcces->TabIndex = 3;
			this->btnProcces->Text = L"Анализ";
			this->btnProcces->UseVisualStyleBackColor = true;
			this->btnProcces->Click += gcnew System::EventHandler(this, &MyForm::btnProcces_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Enabled = false;
			this->btnCancel->Location = System::Drawing::Point(666, 66);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 4;
			this->btnCancel->Text = L"Отмена";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// rtbVideoInfo
			// 
			this->rtbVideoInfo->Enabled = false;
			this->rtbVideoInfo->Location = System::Drawing::Point(12, 68);
			this->rtbVideoInfo->Name = L"rtbVideoInfo";
			this->rtbVideoInfo->Size = System::Drawing::Size(648, 319);
			this->rtbVideoInfo->TabIndex = 5;
			this->rtbVideoInfo->Text = L"";
			// 
			// pbProccess
			// 
			this->pbProccess->Location = System::Drawing::Point(12, 37);
			this->pbProccess->Name = L"pbProccess";
			this->pbProccess->Size = System::Drawing::Size(648, 24);
			this->pbProccess->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
			this->pbProccess->TabIndex = 6;
			this->pbProccess->Value = 20;
			this->pbProccess->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(666, 148);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(686, 224);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(55, 20);
			this->textBox1->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(666, 177);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// comboBox1
			// 
			this->comboBox1->AllowDrop = true;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(328, 161);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 10;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(753, 399);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pbProccess);
			this->Controls->Add(this->rtbVideoInfo);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnProcces);
			this->Controls->Add(this->tbOpenFilePath);
			this->Controls->Add(this->btnOpen);
			this->Controls->Add(this->btnExit);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		String^ str;
		Thread^ demoThread;
		Thread^	processThread;

		char * and_SysStringToChar(System::String^ string) {
			return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
		}	

		delegate void SetTextDelegate(String^ text);

		void SetText(String^ text) {
			if (this->textBox1->InvokeRequired) {
				SetTextDelegate^ d = gcnew SetTextDelegate(this, &MyForm::SetText);
				this->Invoke(d, gcnew array<Object^> {text});
			}
			else {
				this->textBox1->Text = text;
			}
		}


		void disableUI() {
			btnCancel->Enabled = true;
			btnOpen->Enabled = false;
			btnProcces->Enabled = false;
			//tbOpenFilePath->Enabled = false;
			tbOpenFilePath->ReadOnly = true;
			//pbProccess->Visible = true;
		}

		void enableUI() {
			btnCancel->Enabled = false;
			btnOpen->Enabled = true;
			btnProcces->Enabled = true;
			//tbOpenFilePath->Enabled = true;
			tbOpenFilePath->ReadOnly = false;
			//pbProccess->Visible = false;
		}

		void SaveFrame(AVFrame *pFrame, int width, int height, int iFrame) {
			FILE *pFile;
			char szFilename[32];
			int  y;
			//AVPicture picture;
			// Open file

			//sprintf(szFilename, "frame%d.bmp", iFrame);
			sprintf(szFilename, "frame%d.ppm", iFrame);
			pFile = fopen(szFilename, "wb");
			if (pFile == NULL)
				return;
			// Write header
			fprintf(pFile, "P6\n%d %d\n255\n", width, height);

			/*cout << "linesize = " << pFrame->linesize[0] << endl;
			cout << "data = " << pFrame->data[0] << endl;*/
			// Write pixel data
			for (y = 0; y < height; y++)
				fwrite(pFrame->data[0] + y*pFrame->linesize[0], 1, width * 3, pFile);
			/*picture.data;
			picture.linesize;*/

			// Close file
			fclose(pFile);
		}
	
		void SaveDiag(AVFrame *pFrame, int width, int height) {
			FILE *pFile, *pFile2, *txtfile;
			char szFilename[32];
			int  y;

			txtfile = fopen("allPixels.txt", "wb");
			pFile2 = fopen("test.txt", "wb");
			// Open file

			//sprintf(szFilename, "frame%d.bmp", iFrame);
			sprintf(szFilename, "diag.ppm");
			pFile = fopen(szFilename, "wb");
			if (pFile == NULL)
				return;
			// Write header
			//fprintf(pFile, "P6\n%d %d\n255\n", 4, 1);
			fprintf(pFile, "P6\n%d %d\n255\n", width, height);

			// Write pixel data
			//fwrite(pFrame->data[0] + 315*201+316, 3, 4, pFile);
			//fwrite(pFrame->data[0], 3, 10, pFile2);
			uint8_t black[] = { 0, 0, 0 };
			bool f = 0;
			for (int e = 0; e < width * height; ++e) {
				if (f) {
					if (((e % 2) == 0)) {
						fwrite(pFrame->data[0] + 3 * e, 3, 1, pFile);
					}
					else {
						fwrite(black, 3, 1, pFile);
					}
				}
				else {
					if (((e % 2) == 0)) {
						fwrite(black, 3, 1, pFile);
					}
					else {
						fwrite(pFrame->data[0] + 3 * e, 3, 1, pFile);
					}
				}
				if (((e + 1) % width) == 0) {
					f = !f;
				}
			}
			uint8_t *temp;

			for (int j = 0; j < width * height; ++j) {
				temp = pFrame->data[0] + j;
				for (int k = 0; k < AV_NUM_DATA_POINTERS; ++k) {
					fprintf(txtfile, "%d ", int(temp[k]));
					if (((j + 1) % 3) == 0) {
						fprintf(txtfile, "");
					}
				}
			}
			//temp = pFrame->data[0] + 315 * 201 + 316;
			//cout << endl << endl << "!!!!!!!!!!!!!!!!!!temp = " << endl;
			//for (int i = 0; i < AV_NUM_DATA_POINTERS; ++i) {
			//	cout << int(temp[i]) << endl;
			//}

			//cout << endl << endl << "!!!!!!!!!!!!!!!!!!temp = " << temp << endl << endl << endl;
			int num = 0;
			//for (int j = 0; j < width * height; j++) {
			/*if ((pFrame->data[0] + 1) == (pFrame->data[0])) {
			num++;
			}*/
			//}
			//cout << "width * height = " << width*height << endl;
			//cout << "num = " << num << endl;
			//cout <<  pFrame->data[0] + 100 * pFrame->linesize[0] << endl;
			// Close file
			fclose(pFile);
		}
		
		void ThreadBlabla(Object^ paramObj) {
			//this->SetText("Good!");

			/*if (this->textBox1->InvokeRequired) {
				SetTextDelegate^ d = gcnew SetTextDelegate(this, &MyForm::SetText);
				this->Invoke(d, gcnew array<Object^> {"good"});
			}
			else {
				this->textBox1->Text = "dj";
			}*/
		}

		

		void setOpenFileText(String^ text) {
			if (this->tbOpenFilePath->InvokeRequired) {
				SetTextDelegate^ d = gcnew SetTextDelegate(this, &MyForm::setOpenFileText);
				this->Invoke(d, gcnew array<Object^> {text});
			}
			else {
				this->tbOpenFilePath->Text = text;
			}
		}

		void setVideoText(/*System::Windows::Forms::TextBox^ tb,*/ String^ text) {
			if (this->rtbVideoInfo->InvokeRequired) {
				SetTextDelegate^ d = gcnew SetTextDelegate(this, &MyForm::setVideoText);
				this->Invoke(d, gcnew array<Object^> {text});
			}
			else {
				this->rtbVideoInfo->Text = text;
			}
		}


		void processVideo(Object^ paramObj) {
			disableUI();
			setVideoText("");

			enableUI();
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //MessageBox().Show("ds");
				 Application::Exit();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					 //MessageBox::Show(openFileDialog1->FileName);
					 tbOpenFilePath->Text = openFileDialog1->FileName;
				 }
	}

	

	private: System::Void btnProcces_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Thread funcThread(blabla);
				 /*Thread^ workVideoShread = gcnew Thread(gcnew ParameterizedThreadStart(this, &MyForm::blabla));
				 workVideoShread->Start();*/

				 pbProccess->Visible = true;

				 this->processThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &MyForm::processVideo));
				 processThread->Start();

				 
				 rtbVideoInfo->Text = "";
				 
				 /*pbProccess->Style->set(2);
				 pbProccess->Style::set(2);*/
				 pin_ptr<AVFormatContext *> ppFormatCtx = &pFormatCtx;
				 if (avformat_open_input(ppFormatCtx, and_SysStringToChar(tbOpenFilePath->Text), NULL, 0) != 0)
				 {
					 MessageBox::Show("Файл не может быть открыт.");
					 tbOpenFilePath->Text = "";
					 enableUI();
					 //pbProccess->Visible = false;
					 return;
				 }
				 //MessageBox::Show("Oki");
				 


				 if (avformat_find_stream_info(pFormatCtx, NULL)<0)
				 {
					 MessageBox::Show("Информация о потоке не найдена.");
					 tbOpenFilePath->Text = "";
					 enableUI();
					 return;
				 }
				 
				 av_dump_format(pFormatCtx, 0, and_SysStringToChar(tbOpenFilePath->Text), 0);

				 int i;
				 AVCodecContext *pCodecCtxOrig = NULL;
				 AVCodecContext *pCodecCtx = NULL;

				 // Find the first video stream
				 int videoStream = -1;
				 for (i = 0; i < pFormatCtx->nb_streams; i++)
				 {
					 //cout << pFormatCtx->streams[i]->codec->codec_type;
					 if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
					 {
						 videoStream = i;
						 break;
					 }
				 }

				 if (videoStream == -1)
				 {
					 MessageBox::Show("Видеопоток не найден.");
					 tbOpenFilePath->Text = "";
					 enableUI();
					 return; // Didn't find a video stream
					 
				 }

				 pCodecCtx = pFormatCtx->streams[videoStream]->codec;
				 //cout << "pCodecCtx = " << pCodecCtx << endl;
				 double videoFramePerSecond, videoBaseTime, videoDuration;
				 // Кадры в секунду.
				 videoFramePerSecond = av_q2d(pFormatCtx->streams[videoStream]->r_frame_rate);
				 rtbVideoInfo->Text = /*tbVideoInfo->Text + "/n" +*/ "Количество кадров в секунду = " + round(100 * videoFramePerSecond) / 100;
				 //cout << "Кадры в секунду = " << videoFramePerSecond << endl;
				 // базовая единица времени
				 videoBaseTime = av_q2d(pFormatCtx->streams[videoStream]->time_base);
				 //rtbVideoInfo->Text += "\nБазовая единица времени = " + videoBaseTime;
				 //cout << "Базовая единица времени = " << videoBaseTime << endl;
				 // длина видео ролика
				 videoDuration = (unsigned long)pFormatCtx->streams[videoStream]->duration * (/*videoFramePerSecond **/ videoBaseTime);
				 rtbVideoInfo->Text += "\nДлина ролика = " + round(100 * videoDuration) / 100 + "секунд";
				 //cout << "Длина ролика = " << videoDuration << endl;
				 // ширина
				 int width = pFormatCtx->streams[videoStream]->codec->width;
				 rtbVideoInfo->Text += "\nШирина изображени = " + width;
				 //cout << "width = " << width << endl;
				 // высота
				 int height = pFormatCtx->streams[videoStream]->codec->height;
				 rtbVideoInfo->Text += "\nВысота = " + height;
				 //cout << "Height = " << height << endl;
				 

				 AVCodec *pCodec = NULL;
				 // Find the decoder for the video stream
				 pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
				 if (pCodec == NULL) {
					 MessageBox::Show("Данный кодек не поддерживается.");
					 tbOpenFilePath->Text = "";
					 enableUI();
					 //fprintf(stderr, "Unsupported codec!\n");
					 return; // Codec not found
				 }

				 if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
					 MessageBox::Show("Кодек не может быть открыт.");
					 tbOpenFilePath->Text = "";
					 enableUI();
					 return; // Could not open codec

				 }

				 AVFrame *pFrame = NULL;
				 AVFrame *pFrameRGB = NULL;
				 // Allocate video frame
				 pFrame = av_frame_alloc();
				 // Allocate an AVFrame structure
				 pFrameRGB = av_frame_alloc();
				 if (pFrameRGB == NULL) {
					 MessageBox::Show("Кодек не может быть открыт.");
					 tbOpenFilePath->Text = "";
					 enableUI();
					 return;
				 }


				 uint8_t *buffer = NULL;
				 int numBytes;
				 //AVPixelFormat PIX_FMT_RGB24;
				 // Determine required buffer size and allocate buffer
				 numBytes = avpicture_get_size(AV_PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height);
				 buffer = (uint8_t *)av_malloc(numBytes*sizeof(uint8_t));

				 avpicture_fill((AVPicture *)pFrameRGB, buffer, AV_PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height);



				 struct SwsContext *sws_ctx = NULL;
				 int frameFinished;
				 AVPacket packet;
				 // initialize SWS context for software scaling
				 sws_ctx = sws_getContext(pCodecCtx->width,
					 pCodecCtx->height,
					 pCodecCtx->pix_fmt,
					 pCodecCtx->width,
					 pCodecCtx->height,
					 AV_PIX_FMT_RGB24,
					 SWS_BILINEAR,
					 NULL,
					 NULL,
					 NULL
					 );

				 i = 0;
				 bool flag = false;
				 clock_t time;
				 time = clock();
				 pbProccess->Visible = true;

				 while (av_read_frame(pFormatCtx, &packet) >= 0) {
					 // Is this a packet from the video stream?
					 if (packet.stream_index == videoStream) {
						 // Decode video frame
						 avcodec_decode_video2(pCodecCtx, pFrame, &frameFinished, &packet);

						 // Did we get a video frame?
						 if (frameFinished) {
							 //if (!(i % 100)) {
							 //	cout << "Frame#" << i << endl;
							 //}
							 // Convert the image from its native format to RGB
							 sws_scale(sws_ctx, (uint8_t const * const *)pFrame->data,
								 pFrame->linesize, 0, pCodecCtx->height,
								 pFrameRGB->data, pFrameRGB->linesize);
							 if (!flag) {
								 flag = true;
								 SaveDiag(pFrameRGB, pCodecCtx->width, pCodecCtx->height);
							 }
							 // Save the frame to disk
							 ++i;
							 if ((115 < i) && (i < 125))
							 {
								 //++i;
								 SaveFrame(pFrameRGB, pCodecCtx->width, pCodecCtx->height, i);
								 //BMPSave(pFrameRGB, width, height, i);
							 }
						 }
					 }

					 // Free the packet that was allocated by av_read_frame
					 av_free_packet(&packet);
				 }
				 clock_t h, m, s, ms;
				 time = clock() - time;
				 h = time / 3600000;
				 time -= h * 3600000;
				 m = time / 60000;
				 time -= m * 60000;
				 s = time / 1000;
				 time -= s * 1000;
				 ms = time;
				 rtbVideoInfo->Text += "\nВремя работы: " + h + ":" + m + ":" + s + ":" + ms;
				 

				 // Free the RGB image
				 av_free(buffer);
				 av_free(pFrameRGB);

				 // Free the YUV frame
				 av_free(pFrame);

				 // Close the codecs
				 avcodec_close(pCodecCtx);
				 avcodec_close(pCodecCtxOrig);

				 // Close the video file
				/* pin_ptr<AVFormatContext *>*/ ppFormatCtx = &pFormatCtx;
				 avformat_close_input(ppFormatCtx);
			
				 enableUI();
				 pbProccess->Visible = false;
				 
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {

				 this->demoThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &MyForm::ThreadBlabla));
				 demoThread->Start();

				 /*if (pbProccess->Visible == true) {
					 pbProccess->Visible = false;
				 }
				 else {
					 pbProccess->Visible = true;
				 }*/
	}
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = str;
			 comboBox1->Items->Add("sdfj");
			 comboBox1->Items->Add("sdfj");
			 comboBox1->Items->Add("sdfj");
			 comboBox1->Items->Add("sdfj");
			 comboBox1->Items->Add("sdfj");
}
};
}
