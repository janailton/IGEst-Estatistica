object Form_Estimativa_Intervalar: TForm_Estimativa_Intervalar
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Intervalos de Confian'#231'a'
  ClientHeight = 257
  ClientWidth = 483
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object TabbedNotebook1: TTabbedNotebook
    Left = 8
    Top = 8
    Width = 465
    Height = 241
    PageIndex = 1
    TabFont.Charset = DEFAULT_CHARSET
    TabFont.Color = clBtnText
    TabFont.Height = -11
    TabFont.Name = 'Tahoma'
    TabFont.Style = []
    TabOrder = 0
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Propor'#231#227'o'
      object GroupBox1: TGroupBox
        Left = 8
        Top = 8
        Width = 433
        Height = 193
        TabOrder = 0
        object Label2: TLabel
          Left = 16
          Top = 25
          Width = 159
          Height = 13
          Caption = 'Propor'#231#227'o                                  ='
        end
        object Label3: TLabel
          Left = 15
          Top = 51
          Width = 152
          Height = 13
          Caption = 'N'#250'mero de itens                      ='
        end
        object Label5: TLabel
          Left = 15
          Top = 77
          Width = 159
          Height = 13
          Caption = 'Confian'#231'a (%)                           ='
        end
        object EditProporcao: TEdit
          Left = 200
          Top = 18
          Width = 201
          Height = 21
          TabOrder = 0
        end
        object EditPropN: TEdit
          Left = 200
          Top = 45
          Width = 203
          Height = 21
          TabOrder = 1
        end
        object EditPropAlfa: TEdit
          Left = 200
          Top = 72
          Width = 203
          Height = 21
          TabOrder = 2
        end
        object btnProporcao: TButton
          Left = 198
          Top = 142
          Width = 202
          Height = 25
          Caption = 'Calcular'
          TabOrder = 3
          OnClick = btnProporcaoClick
        end
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'M'#233'dia com desvio padr'#227'o conhecido'
      object GroupBox3: TGroupBox
        Left = 8
        Top = 8
        Width = 433
        Height = 193
        TabOrder = 0
        object Label9: TLabel
          Left = 16
          Top = 22
          Width = 138
          Height = 13
          Caption = 'M'#233'dia                                  ='
        end
        object Label10: TLabel
          Left = 16
          Top = 76
          Width = 131
          Height = 13
          Caption = 'N'#250'mero de itens               ='
        end
        object Label11: TLabel
          Left = 18
          Top = 105
          Width = 135
          Height = 13
          Caption = 'Confian'#231'a (%)                   ='
        end
        object Label12: TLabel
          Left = 15
          Top = 48
          Width = 137
          Height = 13
          Caption = 'Desvio padr'#227'o                    ='
        end
        object EditMediaDPC: TEdit
          Left = 200
          Top = 18
          Width = 201
          Height = 21
          TabOrder = 0
        end
        object EditNDPC: TEdit
          Left = 199
          Top = 72
          Width = 203
          Height = 21
          TabOrder = 2
        end
        object EditAlfaDPC: TEdit
          Left = 200
          Top = 99
          Width = 203
          Height = 21
          TabOrder = 3
        end
        object EditVarianciaDPC: TEdit
          Left = 199
          Top = 45
          Width = 201
          Height = 21
          TabOrder = 1
        end
        object btnMDPC: TButton
          Left = 200
          Top = 152
          Width = 203
          Height = 25
          Caption = 'Calcular'
          TabOrder = 4
          OnClick = btnMDPCClick
        end
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'M'#233'dia com desvio padr'#227'o desconhecido'
      object GroupBox2: TGroupBox
        Left = 8
        Top = 8
        Width = 433
        Height = 185
        TabOrder = 0
        object Label4: TLabel
          Left = 16
          Top = 25
          Width = 132
          Height = 13
          Caption = 'M'#233'dia                                ='
        end
        object Label6: TLabel
          Left = 16
          Top = 53
          Width = 131
          Height = 13
          Caption = 'Desvio padr'#227'o                  ='
        end
        object Label7: TLabel
          Left = 16
          Top = 81
          Width = 131
          Height = 13
          Caption = 'N'#250'mero de itens               ='
        end
        object Label8: TLabel
          Left = 16
          Top = 107
          Width = 132
          Height = 13
          Caption = 'Confian'#231'a (%)                  ='
        end
        object EditMediaMDPD: TEdit
          Left = 200
          Top = 18
          Width = 201
          Height = 21
          TabOrder = 0
        end
        object EditVarianciaMDPD: TEdit
          Left = 199
          Top = 45
          Width = 203
          Height = 21
          TabOrder = 1
        end
        object EditNMDPD: TEdit
          Left = 199
          Top = 72
          Width = 203
          Height = 21
          TabOrder = 2
        end
        object EditAlfaMDPD: TEdit
          Left = 200
          Top = 99
          Width = 201
          Height = 21
          TabOrder = 3
        end
        object btnMDPD: TButton
          Left = 200
          Top = 142
          Width = 201
          Height = 25
          Caption = 'Calcular'
          TabOrder = 4
          OnClick = btnMDPDClick
        end
      end
    end
  end
end
