object frm_regressao_correlacao: Tfrm_regressao_correlacao
  Left = 240
  Top = 59
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Regress'#227'o e Correla'#231#227'o'
  ClientHeight = 408
  ClientWidth = 689
  Color = clBtnFace
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object TabNotebook: TTabbedNotebook
    Left = 0
    Top = 0
    Width = 681
    Height = 401
    TabFont.Charset = DEFAULT_CHARSET
    TabFont.Color = clBtnText
    TabFont.Height = -11
    TabFont.Name = 'MS Sans Serif'
    TabFont.Style = []
    TabOrder = 0
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Dados'
      object GroupBox1: TGroupBox
        Left = 0
        Top = 8
        Width = 297
        Height = 361
        Caption = 'Entrada'
        Color = clBtnFace
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Label1: TLabel
          Left = 8
          Top = 24
          Width = 60
          Height = 13
          Caption = 'Valores de X'
        end
        object Label2: TLabel
          Left = 8
          Top = 72
          Width = 78
          Height = 13
          Caption = 'Dados inseridos:'
        end
        object Label3: TLabel
          Left = 104
          Top = 24
          Width = 60
          Height = 13
          Caption = 'Valores de Y'
        end
        object EditX: TEdit
          Left = 8
          Top = 40
          Width = 74
          Height = 21
          TabOrder = 0
        end
        object btnAdicionar: TButton
          Left = 200
          Top = 40
          Width = 81
          Height = 25
          Caption = '&Adicionar'
          TabOrder = 2
          OnClick = btnAdicionarClick
        end
        object btnExcluir: TButton
          Left = 200
          Top = 104
          Width = 81
          Height = 25
          Caption = '&Excluir'
          TabOrder = 4
          OnClick = btnExcluirClick
        end
        object btnCalcular: TButton
          Left = 200
          Top = 72
          Width = 81
          Height = 25
          Caption = '&Calcular'
          TabOrder = 3
          OnClick = btnCalcularClick
        end
        object btnExcluirTudo: TButton
          Left = 200
          Top = 136
          Width = 81
          Height = 25
          Caption = 'E&xcluir Tudo'
          TabOrder = 5
          OnClick = btnExcluirTudoClick
        end
        object EditY: TEdit
          Left = 104
          Top = 40
          Width = 73
          Height = 21
          TabOrder = 1
        end
        object VList1: TValueListEditor
          Left = 0
          Top = 91
          Width = 174
          Height = 262
          DisplayOptions = [doAutoColResize, doKeyColFixed]
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goThumbTracking]
          ScrollBars = ssVertical
          TabOrder = 6
          ColWidths = (
            89
            79)
          RowHeights = (
            18)
        end
      end
      object GroupBox2: TGroupBox
        Left = 312
        Top = 8
        Width = 353
        Height = 361
        Caption = 'Resultado'
        Color = clBtnFace
        ParentBackground = False
        ParentColor = False
        TabOrder = 1
        object Memo1: TMemo
          Left = 8
          Top = 16
          Width = 337
          Height = 337
          ReadOnly = True
          TabOrder = 0
        end
      end
    end
  end
end
